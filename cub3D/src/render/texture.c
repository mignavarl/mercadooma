/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:59:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/06/25 11:30:27 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_index(t_data *data, t_ray *ray)
{
	data->game->tx_hit = data->game->tx_south;
	if (ray->door)
	{
		data->game->tx_hit = data->game->tx_door;
		return ;
	}
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->game->tx_hit = data->game->tx_west;
		else
			data->game->tx_hit = data->game->tx_east;
	}
	else
	{
		if (ray->dir_y > 0)
			data->game->tx_hit = data->game->tx_south;
		else
			data->game->tx_hit = data->game->tx_north;
	}
}

uint32_t	get_texture_color(int tex_x, int tex_y, t_data *data)
{
	int		index;
	uint8_t	*pixel;

	index = (tex_y * TX_WIDTH + tex_x) * data->game->tx_hit->bytes_per_pixel;
	pixel = &data->game->tx_hit->pixels[index];
	return ((pixel[0] << 24) | (pixel[1] << 16) | (pixel[2] << 8) | pixel[3]);
}

void	texture_paint(t_data *data, t_ray *ray, int x, int *y)
{
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	uint32_t	color;

	get_texture_index(data, ray);
	tex_x = (int)(ray->wall_x * (double)TX_WIDTH);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex_x = TX_HEIGHT - tex_x - 1;
	step = ((double)TX_HEIGHT / (double)ray->line_height);
	tex_pos = (ray->draw_start - data->win_height / 2
			+ ray->line_height / 2) * step;
	while ((*y) < ray->draw_end)
	{
		tex_y = (int) tex_pos & (TX_HEIGHT - 1);
		tex_pos += step;
		color = get_texture_color(tex_x, tex_y, data);
		mlx_put_pixel(data->game->img, x, (*y), color);
		(*y)++;
	}
}

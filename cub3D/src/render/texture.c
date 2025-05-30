/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:59:18 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/30 13:45:29 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_index(t_data *data, t_ray *ray)
{
	data->game->tx_hit = data->game->tx_south;
	if (ray->side == 0)
	{
		// if (ray->dir_x < 0)
		// 	data->texinfo.index = WEST;
		// else
		// 	data->texinfo.index = EAST;
	}
	else
	{
		// if (ray->dir_y > 0)
		// 	data->texinfo.index = SOUTH;
		// else
		// 	data->texinfo.index = NORTH;
	}
}

void	texture_paint(t_data *data, t_ray *ray, int x, int *y)
{
	int	tex_x;
	int	tex_y;
	double	step;
	double	tex_pos;
	uint32_t color;

	get_texture_index(data, ray);
	tex_x = (int)(ray->wall_x * (double)TX_WIDTH);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= TX_WIDTH)
		tex_x = TX_WIDTH - 1;
	step = 1 * TX_HEIGHT / ray->line_height;
	tex_pos = (ray->draw_start - data->win_height / 2 + ray->line_height / 2) * step;
	while ((*y) < ray->draw_end)
	{
		tex_y = (int) tex_pos & (TX_HEIGHT - 1);
		tex_pos += step;
		int index = (tex_y * TX_WIDTH + tex_x) * data->game->tx_hit->bytes_per_pixel;
		uint8_t* pixel = &data->game->tx_hit->pixels[index];
		uint8_t r = pixel[0];
		uint8_t g = pixel[1];
		uint8_t b = pixel[2];
		uint8_t a = pixel[3];
		color = (r << 24) | (g << 16) | (b << 8) | a;
		// color = data->game->tx_hit->pixels[TX_HEIGHT * tex_y + tex_x];
		if (ray->side == 0)
			color = (color >> 1) & 8355711;
		mlx_put_pixel(data->game->img, x, (*y), color);
		(*y)++;
	}
}

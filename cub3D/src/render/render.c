/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:09:45 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/30 12:56:36 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_pixels(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = 0;
	while (y < ray->draw_start)
	{
		mlx_put_pixel(data->game->img, x, y, data->ceiling);
		y++;
	}
	texture_paint(data, ray, x, &y);
		//mlx_put_pixel(data->game->img, x, y, 0xFFE64FFF); // color de la textura
	while (y < data->game->mlx->height)
	{
		mlx_put_pixel(data->game->img, x, y, data->floor);
		y++;
	}
}

void	render_raycast(t_data *data)
{
	if (has_resized(data->win_height, data->game->mlx->height)
		|| has_resized(data->win_width, data->game->mlx->width))
	{
		mlx_resize_image(data->game->img, data->game->mlx->width, \
			data->game->mlx->height);
		data->win_height = data->game->mlx->height;
		data->win_width = data->game->mlx->width;
	}
	raycast(data->pj, data);
}

void	render(void *content)
{
	t_data	*data;

	data = (t_data *)content;
	move_player(data);
	if (!data->moved)
		return ;
	render_raycast(data);
}

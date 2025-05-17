/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:09:45 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/17 21:12:07 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_pixels(t_data *data, t_ray *ray, int x)
{
	mlx_image_t	*img;
	int			y;

	img = mlx_new_image(data->game->mlx, WIDTH, HEIGHT);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		mlx_put_pixel(img, x, y, 0x00FF0000);
		y++;
	}
	mlx_image_to_window(data->game->mlx, img, 0, 0);
	free(img);
}

void	render_raycast(t_data *data)
{
	//init_ray(data.ray);
	raycast(data->pj, data);
}

void	render(void *content)
{
	t_data	*data = (t_data *)content;
	//IF !PLAYER MOVED RETURN(0)
	render_raycast(data);
}

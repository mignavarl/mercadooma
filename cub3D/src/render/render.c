/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:09:45 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/27 18:33:25 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_pixels(t_data *data, t_ray *ray, int x)
{
	int	y;

	// y = ray->draw_start;
	y = 0;
	//mlx_put_pixel(img, 300, 200, 0xFFFF0000);
	// printf("y = %d\nend = %d\n", y, ray->draw_end);
	while (y < HEIGHT)
	{
		if (y < ray->draw_start)
			mlx_put_pixel(data->game->img, x, y, data->ceiling);
		else if (y > ray->draw_start && y < ray->draw_end)
			mlx_put_pixel(data->game->img, x, y, 0xFFE64FFF);
		else
			mlx_put_pixel(data->game->img, x, y, data->floor);
		y++;
	}
	
	// while (y < ray->draw_end)
	// {
	// 	// printf("x = %d\ny = %d\n", x, y);
	// 	// printf("DATA = %p\n", data->game->img);
	// 	// mlx_put_pixel(data->game->img, x, y, data->ceiling);
	// 	mlx_put_pixel(data->game->img, x, y, 0xFF0000FF);
	// 	// if (ray->side == 1)
	// 	// else if (ray->side == 0)
	// 		// mlx_put_pixel(data->game->img, x, y, 0xFFFF0000);
	// 	y++;
	// }
	mlx_image_to_window(data->game->mlx, data->game->img, 0, 0);
}

void	render_raycast(t_data *data)
{
	//init_ray(data.ray);
	printf("raycasteo\n");
	raycast(data->pj, data);

}

void	render(void *content)
{
	t_data	*data;

	data = (t_data *)content;
	//IF !PLAYER MOVED RETURN(0)
	if (!data->moved)
		return ;
	render_raycast(data);
	data->moved = 0;
}

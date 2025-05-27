/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:03:00 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/27 17:36:12 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*init_ray(void)
{
	t_ray *r;
	
	r = ft_calloc(1, sizeof(t_ray));

	return (r);
	// ray->camera_x = 0;
	// ray->deltadist_x = 0;
	// ray->deltadist_y = 0;
	// ray->dir_x = 0;
	// ray->dir_y = 0;
	// ray->draw_end = 0;
	// ray->draw_start = 0;
	// ray->line_height = 0;
	// ray->map_x = 0;
	// ray->map_y = 0;
	// ray->side = 0;
	// ray->sidedist_x = 0;
	// ray->sidedist_y = 0;
	// ray->step_x = 0;
	// ray->step_y = 0;
	// ray->wall_dist = 0;
	// ray->wall_x = 0;
}

void	init_raycast(int x, t_ray *ray, t_pj *player)
{
	// init_ray(ray);
	ray->camera_x = 2 * x / (double)(WIDTH) - 1;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
	// printf("dir_y = %f -- plane_y = %f -- camera_x = %f\n", player->dir_y, player->plane_y, ray->camera_x);
}

void	calc_dda(t_ray *ray, t_pj *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

void	loop_dda(t_ray *ray, t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_x][ray->map_y] > '0')
			hit = 1;
	}
}

void	calc_line_height(t_ray *ray, t_data *data, t_pj *player)
{
	(void)data;
	if (ray->side == 0)
		ray->wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->wall_dist = ray->sidedist_y - ray->deltadist_y;
	ray->line_height = (int)(HEIGHT / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	raycast(t_pj *player, t_data *data)
{
	t_ray	*ray;
	int		x;

	x = 0;
	ray = ft_calloc(1, sizeof(t_ray));
	while (x < WIDTH)
	{
		init_raycast(x, ray, player);
		calc_dda(ray, player);
		loop_dda(ray, data);
		calc_line_height(ray, data, player);
		update_pixels(data, ray, x);
		x++;
	}
	free(ray);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:48:09 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/06/15 11:46:09 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_data *data)
{
	double	new_x;
	double	new_y;

	if (data->pj->move_y > 0)
	{
		new_x = data->pj->pos_x + data->pj->dir_x * MOVESPEED;
		new_y = data->pj->pos_y + data->pj->dir_y * MOVESPEED;
		if (data->map[(int)new_y][(int)new_x] == '0')
		{
			data->pj->pos_x = new_x;
			data->pj->pos_y = new_y;
		}
	}
	if (data->pj->move_y < 0)
	{
		new_x = data->pj->pos_x - data->pj->dir_x * MOVESPEED;
		new_y = data->pj->pos_y - data->pj->dir_y * MOVESPEED;
		if (data->map[(int)new_y][(int)new_x] == '0')
		{
			data->pj->pos_x = new_x;
			data->pj->pos_y = new_y;
		}
	}
	if (data->pj->move_x > 0)
	{
		new_x = data->pj->pos_x + data->pj->dir_y * MOVESPEED;
		new_y = data->pj->pos_y - data->pj->dir_x * MOVESPEED;
		if (data->map[(int)new_y][(int)new_x] == '0')
		{
			data->pj->pos_x = new_x;
			data->pj->pos_y = new_y;
		}
	}
	if (data->pj->move_x < 0)
	{
		new_x = data->pj->pos_x - data->pj->dir_y * MOVESPEED;
		new_y = data->pj->pos_y + data->pj->dir_x * MOVESPEED;
		if (data->map[(int)new_y][(int)new_x] == '0')
		{
			data->pj->pos_x = new_x;
			data->pj->pos_y = new_y;
		}
	}
	rotate_player(data, data->pj->rotate);
}

void	key_released(t_data *data, keys_t key)
{
	if (key == MLX_KEY_W)
		data->pj->move_y = 0;
	if (key == MLX_KEY_S)
		data->pj->move_y = 0;
	if (key == MLX_KEY_A)
		data->pj->move_x = 0;
	if (key == MLX_KEY_D)
		data->pj->move_x = 0;
	if (key == MLX_KEY_LEFT)
		data->pj->rotate = 0;
	if (key == MLX_KEY_RIGHT)
		data->pj->rotate = 0;
	data->moved -= 1;
}

void	key_pressed(t_data *data, keys_t key)
{
	if (key == MLX_KEY_W)
		data->pj->move_y += 1;
	if (key == MLX_KEY_S)
		data->pj->move_y -= 1;
	if (key == MLX_KEY_A)
		data->pj->move_x += 1;
	if (key == MLX_KEY_D)
		data->pj->move_x -= 1;
	if (key == MLX_KEY_LEFT)
		data->pj->rotate -= 1;
	if (key == MLX_KEY_RIGHT)
		data->pj->rotate += 1;
	data->moved += 1;
}

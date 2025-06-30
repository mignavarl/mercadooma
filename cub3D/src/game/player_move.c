/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:48:09 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/06/26 11:54:54 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_x(t_data *data, int movement)
{
	double	new_x;
	double	new_y;

	new_x = data->pj->pos_x + data->pj->dir_y * MOVESPEED * movement;
	new_y = data->pj->pos_y + data->pj->dir_x * MOVESPEED * (-movement);
	if (new_y < 0 || new_x < 0
		|| new_y >= data->map_lines || new_x >= data->max_size
		|| data->map[(int)new_y][(int)new_x] == ' ')
		return ;
	if (data->map[(int)new_y][(int)new_x] != '1'
		&& data->map[(int)new_y][(int)new_x] != '2')
	{
		data->pj->pos_x = new_x;
		data->pj->pos_y = new_y;
	}
}

void	move_y(t_data *data, int movement)
{
	double	new_x;
	double	new_y;

	new_x = data->pj->pos_x + data->pj->dir_x * MOVESPEED * movement;
	new_y = data->pj->pos_y + data->pj->dir_y * MOVESPEED * movement;
	if (new_y < 0 || new_x < 0
		|| new_y >= data->map_lines || new_x >= data->max_size
		|| data->map[(int)new_y][(int)new_x] == ' ')
		return ;
	if (data->map[(int)new_y][(int)new_x] != '1'
		&& data->map[(int)new_y][(int)new_x] != '2')
	{
		data->pj->pos_x = new_x;
		data->pj->pos_y = new_y;
	}
}

void	move_player(t_data *data)
{
	if (data->pj->move_y != 0)
	{
		move_y(data, data->pj->move_y);
	}
	if (data->pj->move_x != 0)
	{
		move_x(data, data->pj->move_x);
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
	if (key == MLX_KEY_SPACE)
		open_door(data);
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

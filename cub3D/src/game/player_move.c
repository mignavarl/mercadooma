/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:48:09 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/06/18 11:33:38 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_surr_tiles(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = x - 1;
	while (i <= x + 1)
	{
		j = y - 1;
		while (j <= y + 1)
		{
			if (j == y && i == x)
			{
				j++;
				continue ;
			}
			if (data->map[i][j] == '2')
				data->map[i][j] = '.';
			else if (data->map[i][j] == '.')
				data->map[i][j] = '2';
			j++;
		}
		i++;
	}
}

void	open_door(t_data *data)
{
	t_pj	*player;

	player = data->pj;
	get_surr_tiles(data, player->pos_y, player->pos_x);
	render_raycast(data);
}

void	move_player(t_data *data)
{
	double	new_x;
	double	new_y;

	if (data->pj->move_y > 0)
	{
		new_x = data->pj->pos_x + data->pj->dir_x * MOVESPEED;
		new_y = data->pj->pos_y + data->pj->dir_y * MOVESPEED;
		if (data->map[(int)new_y][(int)new_x] < '1')
		{
			data->pj->pos_x = new_x;
			data->pj->pos_y = new_y;
		}
	}
	if (data->pj->move_y < 0)
	{
		new_x = data->pj->pos_x - data->pj->dir_x * MOVESPEED;
		new_y = data->pj->pos_y - data->pj->dir_y * MOVESPEED;
		if (data->map[(int)new_y][(int)new_x] < '1')
		{
			data->pj->pos_x = new_x;
			data->pj->pos_y = new_y;
		}
	}
	if (data->pj->move_x > 0)
	{
		new_x = data->pj->pos_x + data->pj->dir_y * MOVESPEED;
		new_y = data->pj->pos_y - data->pj->dir_x * MOVESPEED;
		if (data->map[(int)new_y][(int)new_x] < '1')
		{
			data->pj->pos_x = new_x;
			data->pj->pos_y = new_y;
		}
	}
	if (data->pj->move_x < 0)
	{
		new_x = data->pj->pos_x - data->pj->dir_y * MOVESPEED;
		new_y = data->pj->pos_y + data->pj->dir_x * MOVESPEED;
		if (data->map[(int)new_y][(int)new_x] < '1')
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:48:09 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/05/27 19:58:59 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_move(t_data *data, keys_t key)
{
	double	new_x;
	double	new_y;

	if (key == MLX_KEY_W)
	{
		new_x = data->pj->pos_x + data->pj->dir_x * MOVESPEED;
		new_y = data->pj->pos_y + data->pj->dir_y * MOVESPEED;
		data->pj->pos_x = new_x;
		data->pj->pos_y = new_y;
	}
	if (key == MLX_KEY_S)
	{
		new_x = data->pj->pos_x - data->pj->dir_x * MOVESPEED;
		new_y = data->pj->pos_y - data->pj->dir_y * MOVESPEED;
		data->pj->pos_x = new_x;
		data->pj->pos_y = new_y;
	}
	if (key == MLX_KEY_A)
	{
		new_x = data->pj->pos_x - data->pj->dir_y * MOVESPEED;
		new_y = data->pj->pos_y + data->pj->dir_x * MOVESPEED;
		data->pj->pos_x = new_x;
		data->pj->pos_y = new_y;
	}
	if (key == MLX_KEY_D)
	{
		new_x = data->pj->pos_x + data->pj->dir_y * MOVESPEED;
		new_y = data->pj->pos_y - data->pj->dir_x * MOVESPEED;
		data->pj->pos_x = new_x;
		data->pj->pos_y = new_y;
	}
	data->moved = 1;
}

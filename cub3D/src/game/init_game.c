/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:39:00 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/18 12:55:03 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_W || \
		keydata.key == MLX_KEY_S || \
		keydata.key == MLX_KEY_A || \
		keydata.key == MLX_KEY_D || \
		keydata.key == MLX_KEY_RIGHT || \
		keydata.key == MLX_KEY_LEFT || \
		keydata.key == MLX_KEY_SPACE)
	{
		if (keydata.action == MLX_PRESS)
			key_pressed(data, keydata.key);
		else if (keydata.action == MLX_RELEASE)
			key_released(data, keydata.key);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->game->mlx);
		free_images(data->game);
		free_all(data);
		mlx_terminate(data->game->mlx);
		exit(0);
	}
}

bool	init_game(t_data *data)
{
	data->game = ft_calloc(1, sizeof(t_game));
	if (!data->game)
		return (false);
	mlx_set_setting(MLX_DECORATED, true);
	data->game->mlx = mlx_init(WIDTH, HEIGHT, "Mercadooma", true);
	if (!data->game->mlx)
		ft_error();
	data->moved = 1;
	if (!save_textures(data->game, data))
		return (free_all(data), FALSE);
	mlx_set_icon(data->game->mlx, data->game->icon);
	if (!save_images(data->game))
		return (free_all(data), FALSE);
	mlx_image_to_window(data->game->mlx, data->game->img, 0, 0);
	data->win_height = HEIGHT;
	data->win_width = WIDTH;
	render(data);
	data->moved = 0;
	mlx_loop_hook(data->game->mlx, render, data);
	mlx_key_hook(data->game->mlx, &my_keyhook, data);
	mlx_loop(data->game->mlx);
	mlx_terminate(data->game->mlx);
	free_game_textures(data->game);
	return (TRUE);
}

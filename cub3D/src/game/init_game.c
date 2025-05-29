/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:39:00 by mignavar          #+#    #+#             */
/*   Updated: 2025/05/29 15:36:09 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_W || \
		keydata.key == MLX_KEY_S || \
		keydata.key == MLX_KEY_A || \
		keydata.key == MLX_KEY_D || \
		keydata.key == MLX_KEY_RIGHT || \
		keydata.key == MLX_KEY_LEFT)
	{
		if (keydata.action == MLX_PRESS)
			key_pressed(data, keydata.key);
		else if (keydata.action == MLX_RELEASE)
		{
		    key_released(data, keydata.key);
		}
	}

	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
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
	// MLX allows you to define its core behaviour before startup.
	data->game = ft_calloc(1, sizeof(t_game));
	if (!data->game)
		return false;
	mlx_set_setting(MLX_DECORATED, true);
	data->game->mlx = mlx_init(WIDTH, HEIGHT, "42Balls", false); //TODO en mi portatil no se ejecuta esta linea
	if (!data->game->mlx)
		ft_error();
	ft_printf("WINDOW => %p\t WIDTH => %i\t HEIGHT => %i\n", data->game->mlx->window, data->game->mlx->width, data->game->mlx->height);
	/* Do stuff */
	data->moved = 1;
	if (!save_textures(data->game, data))
		return (free_all(data), FALSE);
	mlx_set_icon(data->game->mlx, data->game->icon);
	if (!save_images(data->game))
		return (free_all(data), FALSE);
	mlx_image_to_window(data->game->mlx, data->game->img, 0, 0);
	render(data);
	data->moved = 0;
	//--------------
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_loop_hook(data->game->mlx, ft_hook, data->game->mlx);
	mlx_loop_hook(data->game->mlx, render, data);
	mlx_key_hook(data->game->mlx, &my_keyhook, data);
	mlx_loop(data->game->mlx);
	mlx_terminate(data->game->mlx);
	free_game_textures(data->game);
	return (TRUE);
}

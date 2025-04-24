/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:39:00 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/24 17:16:34 by mignavar         ###   ########.fr       */
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

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_data *data;

	data = param;
	// If we PRESS the 'J' key, print "Hello".
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
		free_all(data);
		exit(0);
	}
		
}

bool	init_game(t_data *data)
{
	t_game	game;

	// MLX allows you to define its core behaviour before startup.
	ft_bzero(&game, sizeof(t_game));
	mlx_set_setting(MLX_DECORATED, true);
	game.mlx = mlx_init(256, 256, "42Balls", true);
	if (!game.mlx)
		ft_error();

	/* Do stuff */
	mlx_set_icon(game.mlx, game.icon);//TODO: poner icono
	if (!save_textures(&game, data))
		return (free_all(data), FALSE);
	if (!save_images(&game, data))
		return (free_all(data), FALSE);
	//--------------
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	//mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(game.mlx, &my_keyhook, data);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:47:49 by mignavar          #+#    #+#             */
/*   Updated: 2025/05/27 13:03:20 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_images(t_game *game)
{
	free_game_textures(game);
	if (game->im_north)
		mlx_delete_image(game->mlx, game->im_north);
	if (game->im_south)
		mlx_delete_image(game->mlx, game->im_south);
	if (game->im_east)
		mlx_delete_image(game->mlx, game->im_east);
	if (game->im_west)
		mlx_delete_image(game->mlx, game->im_west);
}

bool	save_images(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	// memset(game->img->pixels, 0, WIDTH * HEIGHT * sizeof(int32_t));
	printf("DATA = %p\n", game->img);
	mlx_put_pixel(game->img, 10, 10, 0xFF0000FF);

	game->im_north = mlx_texture_to_image(game->mlx, game->tx_north);
	game->im_south = mlx_texture_to_image(game->mlx, game->tx_south);
	game->im_east = mlx_texture_to_image(game->mlx, game->tx_east);
	game->im_west = mlx_texture_to_image(game->mlx, game->tx_west);
	if (!game->im_north || !game->im_south || !game->im_east || !game->im_west)
	{
		free_images(game);
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	return (TRUE);
}

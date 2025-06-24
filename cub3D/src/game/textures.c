/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:30:01 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/24 17:13:33 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game_textures(t_game *game)
{
	if (game->tx_north)
		mlx_delete_texture(game->tx_north);
	if (game->tx_south)
		mlx_delete_texture(game->tx_south);
	if (game->tx_east)
		mlx_delete_texture(game->tx_east);
	if (game->tx_west)
		mlx_delete_texture(game->tx_west);
	if (game->icon)
		mlx_delete_texture(game->icon);
	if (game->tx_door)
		mlx_delete_texture(game->tx_door);
	if (game->tx_kart)
		mlx_delete_texture(game->tx_kart);
}

bool	save_textures(t_game *game, t_data *data)
{
	game->tx_north = mlx_load_png(data->no_texture);
	game->tx_south = mlx_load_png(data->so_texture);
	game->tx_east = mlx_load_png(data->ea_texture);
	game->tx_west = mlx_load_png(data->we_texture);
	game->icon = mlx_load_png("./textures/icon.png");
	game->tx_door = mlx_load_png("./textures/puerta_pixel.png");
	game->tx_kart = mlx_load_png("./textures/carro_pixel.png");
	if (!game->tx_north || !game->tx_south || !game->tx_east
		|| !game->tx_west || !game->icon || !game->tx_door
		|| !game->tx_kart)
	{
		free_game_textures(game);
		mlx_terminate(game->mlx);
		return (FALSE);
	}
	return (TRUE);
}

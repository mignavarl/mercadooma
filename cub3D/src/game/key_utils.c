/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:38:36 by dlopez-l          #+#    #+#             */
/*   Updated: 2025/06/25 11:39:12 by dlopez-l         ###   ########.fr       */
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

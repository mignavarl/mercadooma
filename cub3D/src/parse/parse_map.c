/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:27:22 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/08 18:17:35 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	map_letter(char **map)
{
	int	line;
	int	pos;

	line = 0;
	while (map[line])
	{
		pos = 0;
		while (map[line][pos])
		{
			if (map[line][pos] != '0' && map[line][pos] != '1'
				&& map[line][pos] != 'N' && map[line][pos] != 'S'
				&& map[line][pos] != 'E' && map[line][pos] != 'W'
				&& map[line][pos] != ' ')
				return (FALSE);
			pos++;
		}
		line++;
	}
	return (TRUE);
}

bool	parse_map(t_data *data)
{
	if (!map_letter(data->map))
	{
		print_error("Incorrect characters in map");
		free_all(data);
		return (FALSE);
	}
	printf(GREEN"Letras bien"END"\n");
	return (TRUE);
}

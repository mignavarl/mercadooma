/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:27:22 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/18 11:14:56 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	repeat_init(char **map, int line, int pos)
{
	bool	init;

	init = FALSE;
	while (map[line])
	{
		pos = 0;
		while (map[line][pos])
		{
			if (init == FALSE && (map[line][pos] == 'N'
				|| map[line][pos] == 'S' || map[line][pos] == 'E'
				|| map[line][pos] == 'W'))
				init = TRUE;
			else if (init == TRUE && (map[line][pos] == 'N'
				|| map[line][pos] == 'S' || map[line][pos] == 'E'
				|| map[line][pos] == 'W'))
				return (print_error("Multiple start position"), FALSE);
			pos++;
		}
		line++;
	}
	if (!init)
		print_error("No start position");
	return (init);
}

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
				&& map[line][pos] != ' ' && map[line][pos] != '2')
				return (print_error("Incorrect characters in map"), FALSE);
			pos++;
		}
		line++;
	}
	if (!repeat_init(map, 0, 0))
		return (FALSE);
	return (TRUE);
}

bool	view_top_down(char **map, int total_line)
{
	int	pos;

	pos = 0;
	while (map[0][pos])
	{
		if (map[0][pos] != '1' && map[0][pos] != ' ')
			return (FALSE);
		pos++;
	}
	pos = 0;
	while (map[total_line][pos])
	{
		if (map[total_line][pos] != '1' && map[total_line][pos] != ' ')
			return (FALSE);
		pos++;
	}
	return (TRUE);
}

bool	view_borders(char **map)
{
	int	line;

	line = 0;
	while (map[line])
	{
		if ((map[line][0] != '1' && map[line][0] != ' ')
			|| (map[line][ft_strlen(map[line]) - 1] != '1'
			&& map [line][ft_strlen(map[line]) - 1] != ' '))
			return (FALSE);
		line++;
	}
	line--;
	if (!view_top_down(map, line))
		return (FALSE);
	if (!check_holes(map, line))
		return (FALSE);
	return (TRUE);
}

bool	parse_map(t_data *data)
{
	if (!map_letter(data->map))
	{
		free_map(data);
		return (FALSE);
	}
	if (!view_borders(data->map))
	{
		print_error("Map not closed");
		free_map(data);
		return (FALSE);
	}
	printf(GREEN"Mapa bien"END"\n");
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_holes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:47:29 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/18 15:26:13 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_side(int c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == '2')
		return (FALSE);
	return (TRUE);
}

bool	check_up_down(char **map, int line, int pos)
{
	if (map[line][pos] != ' ' && map[line][pos] != '1')
	{
		if ((int)ft_strlen(map[line - 1]) > pos
			&& map[line - 1][pos] == ' ')
			return (FALSE);
		if ((int)ft_strlen(map[line - 1]) < pos)
			return (FALSE);
		if ((int)ft_strlen(map[line + 1]) > pos
			&& map[line + 1][pos] == ' ')
			return (FALSE);
		if ((int)ft_strlen(map[line + 1]) < pos)
			return (FALSE);
	}
	return (TRUE);
}

bool	check_holes(char **map, int total_line)
{
	int	pos;
	int	line;

	line = 1;
	while (line < total_line)
	{
		pos = 1;
		while (map[line][pos] != '\0')
		{
			if (map[line][pos] == ' ' && (!check_side(map[line][pos - 1])
				|| !check_side(map[line][pos + 1])))
				return (FALSE);
			if (!check_up_down(map, line, pos))
				return (FALSE);
			pos++;
		}
		line++;
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:06:23 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/26 11:54:34 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_end_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

bool	fill_map(t_data *data)
{
	int		i;
	char	**new_map;

	new_map = ft_calloc(data->map_lines + 1, sizeof(char *));
	if (!new_map)
		return (FALSE);
	i = 0;
	while (data->map[i])
	{
		new_map[i] = ft_threejoin("111", data->map[i], "111");
		i++;
	}
	ft_free_double(&data->map);
	data->map = new_map;
	return (TRUE);
}

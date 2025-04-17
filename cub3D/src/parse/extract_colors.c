/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:20:52 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/16 15:59:36 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*search_color(char **doc, char *color, char *dimin)
{
	int	line;
	int	pos;

	line = 0;
	while (doc[line])
	{
		pos = 0;
		while (doc[line][pos] <= ' ' && doc[line][pos])
			pos++;
		if (ft_strncmp(&doc[line][pos], dimin, 1) == 0)
		{
			pos++;
			while (doc[line][pos] <= ' ' && doc[line][pos])
				pos++;
			color = ft_substr(doc[line], pos,
					(ft_strlen(doc[line]) - pos - 1));
			if (!color)
				return (NULL);
			if (ft_strlen(color) <= 1)
				return (free(color), NULL);
			return (color);
		}
		line++;
	}
	return (NULL);
}

void	free_color(t_data *data, int col)
{
	free_texture(data, 5);	
	if (col >= 1)
		free(data->c_color);
	if (col >= 2)
		free(data->f_color);
}

bool	extract_color(char **doc, t_data *data)
{
	int	col;

	col = 0;
	data->c_color = search_color(doc, data->c_color, "C");
	if (!data->c_color)
		return (free_color(data, col), FALSE);
	col++;
	data->f_color = search_color(doc, data->f_color, "F");
	if (!data->f_color)
		return (free_color(data, col), FALSE);
	printf("COLORES:\nC = '%s'\nF = '%s'\n", data->c_color, data->f_color);
	return (TRUE);
}

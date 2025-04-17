/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:27:26 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/16 15:55:30 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*search_texture(char **doc, char *texture, char *dimin)
{
	int	line;
	int	pos;

	line = 0;
	while (doc[line])
	{
		pos = 0;
		while (doc[line][pos] <= ' ' && doc[line][pos])
			pos++;
		if (ft_strncmp(&doc[line][pos], dimin, 2) == 0)
		{
			pos += 2;
			while (doc[line][pos] <= ' ' && doc[line][pos])
				pos++;
			texture = ft_substr(doc[line], pos,
					(ft_strlen(doc[line]) - pos - 1));
			if (!texture)
				return (NULL);
			if (ft_strlen(texture) <= 1)
				return (free(texture), NULL);
			return (texture);
		}
		line++;
	}
	return (NULL);
}

void	free_texture(t_data *data, int tx)
{
	ft_free_double(&data->doc);
	ft_free_double(&data->map);
	if (tx >= 1)
		free(data->no_texture);
	if (tx >= 2)
		free(data->so_texture);
	if (tx >= 3)
		free(data->ea_texture);
	if (tx >= 4)
		free(data->we_texture);
}

bool	extract_texture(char **doc, t_data *data)
{
	int	tx;

	tx = 0;
	data->no_texture = search_texture(doc, data->no_texture, "NO");
	if (!data->no_texture)
		return (free_texture(data, tx), FALSE);
	tx++;
	data->so_texture = search_texture(doc, data->so_texture, "SO");
	if (!data->so_texture)
		return (free_texture(data, tx), FALSE);
	tx++;
	data->ea_texture = search_texture(doc, data->ea_texture, "EA");
	if (!data->ea_texture)
		return (free_texture(data, tx), FALSE);
	tx++;
	data->we_texture = search_texture(doc, data->we_texture, "WE");
	if (!data->we_texture)
		return (free_texture(data, tx), FALSE);
	printf("TODAS LAS TEXTURAS:\nNO = '%s'\nSO = '%s'\nEA = '%s'\nWE = '%s'\n", data->no_texture, data->so_texture, data->ea_texture, data->we_texture);
	return (TRUE);
}

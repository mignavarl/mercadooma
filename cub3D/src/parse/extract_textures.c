/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:27:26 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/15 18:17:44 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	search_texture(char **doc, char *texture, char *dimin, int tx)
{
	int	line;
	int	pos;

	line = 0;
	while (doc[line])
	{
		pos = 0;
		while (doc[line][pos] <= ' ')
			pos++;
		if (ft_strncmp(&doc[line][pos], dimin, 2) == 0)
		{
			while (doc[line][pos] <= ' ')
				pos++;
			texture = ft_substr(doc[line], pos,
				((int)ft_strlen(doc[line]) - pos));
			if (!texture)
				return (-1);
			return (tx + 1);
		}
		line++;
	}
	return (tx);
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
	tx = search_texture(doc, data->no_texture, "NO", tx);
	if (tx < 1)
		return (free_texture(data, tx), FALSE);
	tx = search_texture(doc, data->so_texture, "SO", tx);
	if (tx < 2)
		return (free_texture(data, tx), FALSE);
	tx = search_texture(doc, data->ea_texture, "EA", tx);
	if (tx < 3)
		return (free_texture(data, tx), FALSE);
	tx = search_texture(doc, data->we_texture, "WE", tx);
	if (tx < 4)
		return (free_texture(data, tx), FALSE);
	/*TODO:search color
	tx = search_texture(doc, data->f_color, "F", tx);
	if (tx != 4)
		return (free_texture(data, doc, tx), FALSE);
	tx = search_texture(doc, data->c_color, "C", tx);
	if (tx != 5)
		return (free_texture(data, doc, tx), FALSE);*/
	printf("TODAS LAS TEXTURAS:\nNO = %s\nSO = %s\nEA = %s\nWE = %s\n", data->no_texture, data->so_texture, data->ea_texture, data->we_texture);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:47:35 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/26 12:00:41 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	extract_doc(t_data *data, char *arg)
{
	int	line;
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	data->doc = ft_calloc(data->total_line + 2, sizeof(char *));
	if (!data->doc)
		return (FALSE);
	line = 0;
	while (line <= data->total_line)
	{
		data->doc[line] = get_next_line(fd);
		if (!data->doc[line])
			break ;
		line++;
	}
	close(fd);
	data->doc[line] = NULL;
	return (TRUE);
}

bool	extract_map(t_data *data)
{
	int	line;
	int	m_line;

	line = data->total_line;
	while (ft_strcmp(&data->doc[line][0], "\n") && line > 0)
		line--;
	if (line == 0)
		return (print_error("Map no separated"), FALSE);
	data->map = ft_calloc((data->total_line - line) + 1, sizeof(char *));
	if (!data->map)
		return (FALSE);
	line++;
	m_line = 0;
	while (line <= data->total_line)
	{
		data->map[m_line] = ft_strtrim(data->doc[line], "\n");
		if (data->max_size < (int)ft_strlen(data->map[m_line]) + 3)
			data->max_size = ft_strlen(data->map[m_line]) + 3;
		m_line++;
		line++;
	}
	data->map_lines = m_line;
	return (TRUE);
}

void	player_pos(t_data *data, char **map)
{
	int		line;
	int		pos;

	data->pj = ft_calloc(1, sizeof(t_pj));
	line = 0;
	while (map[line])
	{
		pos = 0;
		while (map[line][pos])
		{
			if (map[line][pos] == 'N' || map[line][pos] == 'S'
				|| map[line][pos] == 'E' || map[line][pos] == 'W')
			{
				data->pj->pos_x = pos;
				data->pj->pos_y = line;
				data->pj->view = map[line][pos];
				init_player_dir(data);
				return ;
			}
			pos++;
		}
		line++;
	}
}

bool	init_parse(t_data *data, char *arg)
{
	if (!extract_doc(data, arg))
		return (print_error("Problem with document"), FALSE);
	if (!extract_map(data))
		return (FALSE);
	if (!parse_map(data))
		return (FALSE);
	if (!fill_map(data))
		return (FALSE);
	player_pos(data, data->map);
	if (!extract_texture(data->doc, data))
		return (print_error("Texture not found"), FALSE);
	if (!extract_color(data->doc, data))
		return (print_error("Color not found"), FALSE);
	if (!extract_rgba(data))
		return (print_error("The color range has to be between 0 - 255"),
			FALSE);
	return (TRUE);
}

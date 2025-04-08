/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:47:35 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/08 18:20:22 by mignavar         ###   ########.fr       */
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
	data->doc = ft_calloc(data->total_line + 1, sizeof(char *));
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
	return (TRUE);
}

bool	extract_map(t_data *data)
{
	int	line;
	int	m_line;

	line = data->total_line;
	while (ft_strcmp(&data->doc[line][0], "\n"))
		line--;
	data->map = ft_calloc((data->total_line - line) + 1, sizeof(char *));
	if (!data->map)
		return (FALSE);
	line++;
	m_line = 0;
	while (line <= data->total_line)
	{
		data->map[m_line] = ft_strtrim(ft_strdup(data->doc[line]), "\n");
		m_line++;
		line++;
	}
	return (TRUE);
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	printf(YELLOW"MAPA"END"\n");
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	printf(YELLOW"FIN MAPA"END"\n");
}

bool	init_parse(t_data *data, char *arg)
{
	if (!extract_doc(data, arg))
	{
		print_error("Problem with document");
		return (FALSE);
	}
	printf(RED"Total line = %d"END"\n", data->total_line);
	if (!extract_map(data))
		return (FALSE);
	print_map(data);
	if (!parse_map(data))
		return (FALSE);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-l <dlopez-l@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:59:40 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/25 15:34:14 by dlopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_line(char *doc)
{
	int		fd;
	int		lines;
	char	*buf;

	fd = open(doc, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		free(buf);
		lines++;
	}
	free(buf);
	close(fd);
	return (lines - 1);
}

void	free_all(t_data *data)
{
	if (data->doc)
		ft_free_double(&data->doc);
	if (data->map)
		ft_free_double(&data->map);
	free(data->no_texture);
	free(data->so_texture);
	free(data->ea_texture);
	free(data->we_texture);
	free(data->c_color);
	free(data->f_color);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (print_error("Incorrect number of arguments"), 1);
	if (ft_strncmp(&argv[1][(ft_strlen(argv[1]) - 4)], ".cub", 4) != 0)
		return (print_error("Extension not valid"), 1);
	data = ft_calloc(1, sizeof(t_data));
	data->total_line = count_line(argv[1]);
	if (data->total_line < 10)
		return (print_error("Invalid document"), 1);
	if (!init_parse(data, argv[1]))
		return (1);
	if (!init_game(data))
		return (1);
	free_all(data);
	return (0);
}

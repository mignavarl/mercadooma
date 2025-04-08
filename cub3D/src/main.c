/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:59:40 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/08 18:18:05 by mignavar         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_error("Incorrect number of arguments");
		return (1);
	}
	if (ft_strncmp(&argv[1][(ft_strlen(argv[1]) - 4)], ".cub", 4) != 0)
	{
		print_error("Extension not valid");
		return (1);
	}
	ft_bzero(&data, sizeof(t_data));
	data.total_line = count_line(argv[1]);
	if (data.total_line < 0)
	{
		print_error("Invalid document");
		return (1);
	}
	if (!init_parse(&data, argv[1]))
		return (1);
	free_all(&data);
	return (0);
}

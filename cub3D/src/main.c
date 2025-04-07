/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:59:40 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/07 17:42:52 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Incorrect number of arguments\n");
		return (1);
	}
	
	ft_bzero(&data, sizeof(t_data));
	data.total_line = count_line(argv[1]);
	init_parse(&data);
	return (0);
}
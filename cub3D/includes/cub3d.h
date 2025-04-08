/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:00:05 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/08 18:09:24 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# define TRUE 1
# define FALSE 0

//COLORS
# define RED	"\001\033[1;31m\002"
# define GREEN	"\001\033[1;32m\002"
# define YELLOW	"\001\033[1;33m\002"
# define BLUE	"\001\033[1;34m\002"
# define PURPLE	"\001\033[1;95m\002"
# define CYAN	"\001\033[1;36m\002"
# define WHITE	"\001\033[1;37m\002"
# define END	"\001\033[0m\002"

typedef struct s_data	t_data;

struct s_data
{
	char			**doc;
	char			**map;
	char			*no_texture;
	char			*so_texture;
	char			*ea_texture;
	char			*we_texture;
	unsigned int	f_color;
	unsigned int	c_color;
	int				total_line;
};

//----------- PARSE -----------------
//init_parse.c
bool	init_parse(t_data *data, char *arg);

//parse_map.c
bool	parse_map(t_data *data);

//----------- ERROR -----------------
void	print_error(char *text);
void	free_all(t_data *data);

#endif
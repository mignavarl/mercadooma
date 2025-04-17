/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_rgba.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:38:40 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/17 16:02:26 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	free_colors(char *r, char *g, char *b)
{
	if (r)
		free(r);
	if (g)
		free(g);
	if (b)
		free(b);
}

bool	rgba_ceiling(t_data *data)
{
	char	*red;
	char	*green;
	char	*blue;

	if (!check_str_color(data->c_color))
		return (FALSE);
	red = NULL;
	green = NULL;
	blue = NULL;
	red = find_red(red, data->c_color);
	green = find_green(green, data->c_color);
	blue = find_blue(blue, data->c_color);
	if (!red || !green || !blue)
	{
		free_colors(red, green, blue);
		return (FALSE);
	}
	data->ceiling = get_rgba(ft_atoi(red), ft_atoi(green), ft_atoi(blue), 255);
	free_colors(red, blue, green);
	return (TRUE);
}

bool	rgba_floor(t_data *data)
{
	char	*red;
	char	*green;
	char	*blue;

	if (!check_str_color(data->f_color))
		return (FALSE);
	red = NULL;
	green = NULL;
	blue = NULL;
	red = find_red(red, data->f_color);
	green = find_green(green, data->f_color);
	blue = find_blue(blue, data->f_color);
	if (!red || !green || !blue)
	{
		free_colors(red, green, blue);
		return (FALSE);
	}
	data->floor = get_rgba(ft_atoi(red), ft_atoi(green), ft_atoi(blue), 255);
	free_colors(red, blue, green);
	return (TRUE);
}

bool	extract_rgba(t_data *data)
{
	if (!rgba_ceiling(data))
	{
		free_all(data);
		return (NULL);
	}
	if (!rgba_floor(data))
	{
		free_all(data);
		return (NULL);
	}
	printf("RGBA:\nCeiling =\t'%d'\nFloor =\t\t'%d'\n", data->ceiling, data->floor);
	return (TRUE);
}

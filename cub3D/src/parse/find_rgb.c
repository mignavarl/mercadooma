/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:17:22 by mignavar          #+#    #+#             */
/*   Updated: 2025/04/17 15:54:40 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*find_red(char *red, char *color)
{
	int	i;

	i = 0;
	while (color[i] != ',')
		i++;
	red = ft_substr(color, 0, i);
	if (!red)
		return(NULL);
	i = ft_atoi(red);
	if (i > 255 || i < 0)
		return (NULL);
	return (red);
}

char	*find_green(char *green, char *color)
{
	int	i;
	int	init;
	
	i = 0;
	while (color[i] != ',')
		i++;
	i++;
	init = i;
	while (color[i] != ',')
		i++;
	green = ft_substr(color, init, (i - init));
	if (!green)
		return (NULL);
	i = ft_atoi(green);
	if (i > 255 || i < 0)
		return (NULL);
	return (green);
}

char	*find_blue(char *blue, char *color)
{
	int	i;
	int	init;

	i = 0;
	while (color[i])
		i++;
	init = i;
	while (color[init] != ',')
		init--;
	init++;
	blue = ft_substr(color, init, (i - init));
	if (!blue)
		return (NULL);
	i = ft_atoi(blue);
	if (i > 255 || i < 0)
		return (NULL);
	return (blue);
}

bool	check_str_color(char *color)
{
	int	i;
	int	com;

	i = 0;
	com = 0;
	while (color[i] != '\n' && color[i])
	{
		if (!ft_isdigit(color[i]) && color[i] != ',')
			return (NULL);
		if (color[i] == ',')
			com++;
		i++;
	}
	if (com != 2)
		return (FALSE);
	return (TRUE);
}

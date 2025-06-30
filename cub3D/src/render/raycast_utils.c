/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:57:50 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/26 11:58:13 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_ray(t_data *data, int map_x, int map_y)
{
	return (map_y >= 0 && map_y <= data->map_lines && map_x >= 0
		&& map_x <= (int)ft_strlen(data->map[map_y]));
}

int	check_hit(t_data *data, t_ray *ray)
{
	if (data->map[(int)ray->map_y][(int)ray->map_x] == '1'
		|| data->map[(int)ray->map_y][(int)ray->map_x] == '2'
		|| data->map[(int)ray->map_y][(int)ray->map_x] == ' ')
	{
		if (data->map[(int)ray->map_y][(int)ray->map_x] == '2')
			ray->door = 1;
		return (1);
	}
	return (0);
}

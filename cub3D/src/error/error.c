/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:37:24 by mignavar          #+#    #+#             */
/*   Updated: 2025/06/18 12:55:26 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *text)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(text, 2);
}

void	free_map(t_data *data)
{
	if (data->doc)
		ft_free_double(&data->doc);
	if (data->map)
		ft_free_double(&data->map);
}

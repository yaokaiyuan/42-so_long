/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:05:10 by paradari          #+#    #+#             */
/*   Updated: 2024/08/06 16:05:12 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_left(t_data *data)
{
	int	x;
	int	y;

	x = data->pos_x;
	y = data->pos_y;
	fill_vertical(data, x, y);
	ft_full_fill(data);
	if (ft_check_left(data))
		return (1);
	return (0);
}

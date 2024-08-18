/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:50:51 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/08/18 22:31:36 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player_position(t_data *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (data->tmp[i])
	{
		j = 0;
		while (data->tmp[i][j])
		{
			if (data->tmp[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	*x = -1;
	*y = -1;
}

void	ft_flood_fill(t_data *data, int y, int x)
{
	if (y < 0 || x < 0 || !data->tmp[y]
		|| data->tmp[y][x] == '1' || data->tmp[y][x] == 'X')
		return ;
	data->tmp[y][x] = 'X';
	ft_flood_fill(data, y - 1, x);
	ft_flood_fill(data, y + 1, x);
	ft_flood_fill(data, y, x - 1);
	ft_flood_fill(data, y, x + 1);
}

int	ft_check_unvisited_elements(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->tmp[i])
	{
		j = 0;
		while (data->tmp[i][j])
		{
			if (data->tmp[i][j] == 'C' || data->tmp[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_reachable(t_data *data)
{
	int	player_x;
	int	player_y;

	ft_find_player_position(data, &player_x, &player_y);
	if (player_x == -1 || player_y == -1)
		return (1);
	ft_flood_fill(data, player_y, player_x);
	return (ft_check_unvisited_elements(data));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:57:09 by paradari          #+#    #+#             */
/*   Updated: 2024/08/06 15:57:13 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_full_fill(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->tmp[i])
	{
		j = 0;
		while (data->tmp[i][j] && data->tmp[i][j] != '\n')
		{
			if (data->tmp[i][j] != '1' && check_x(data, i, j))
				data->tmp[i][j] = 'X';
			j++;
		}
		i++;
	}
}

int	check_x(t_data *data, int y, int x)
{
	if (data->tmp[y - 1][x] == 'X' || data->tmp[y + 1][x] == 'X'
			|| data->tmp[y][x - 1] == 'X' || data->tmp[y][x + 1] == 'X')
		return (1);
	return (0);
}

void	fill_horizon(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (data->tmp[y][x - i] != '1' && data->tmp[y][x - i])
	{
		data->tmp[y][x - i] = 'X';
		i++;
	}
	i = 0;
	while (data->tmp[y][x + i] != '1' && data->tmp[y][x + i])
	{
		data->tmp[y][x + i] = 'X';
		i++;
	}
}

void	fill_vertical(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (data->tmp[y - i][x] != '1' && data->tmp[y - i][x])
	{
		data->tmp[y - i][x] = 'X';
		if (data->tmp[y - i][x - 1] != '1')
			fill_horizon(data, x - 1, y - i);
		if (data->tmp[y - i][x + 1] != '1')
			fill_horizon(data, x + 1, y - i);
		i++;
	}
	i = 0;
	while (data->tmp[y + i][x] != '1' && data->tmp[y + i][x])
	{
		data->tmp[y + i][x] = 'X';
		if (data->tmp[y + i][x - 1] != '1')
			fill_horizon(data, x - 1, y + i);
		if (data->tmp[y + i][x + 1] != '1')
			fill_horizon(data, x + 1, y + i);
		i++;
	}
}

int	ft_check_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->tmp[i])
	{
		j = 0;
		while (data->tmp[i][j] && data->tmp[i][j] != '\n')
		{
			if (data->tmp[i][j] == 'C' || data->tmp[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

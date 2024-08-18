/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:49:42 by paradari          #+#    #+#             */
/*   Updated: 2024/08/19 02:11:15 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->line)
	{
		j = 0;
		while (j < data->column)
		{
			if (!(ft_strchr("01PCE", data->map[i][j])))
			{
				ft_putstr_fd("At least 1 character not 0/1/P/C/E\n", 1);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_missing(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->line)
	{
		j = 0;
		while (j < data->column)
		{
			if (data->map[i][j] == 'P')
				ft_set_status('P', data, i, j);
			else if (data->map[i][j] == 'C')
				data->c_status++;
			else if (data->map[i][j] == 'E')
				ft_set_status('E', data, i, j);
			j++;
		}
		i++;
	}
	if (data->p_status == 0 || data->c_status == 0 || data->e_status == 0)
		return (1);
	else
		return (0);
}

int	check_rect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->line)
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
			j++;
		if (j != data->column)
		{
			ft_putstr_fd("Map Error\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i] && data->map[0][i] != '\n')
	{
		if (data->map[0][i] != '1' || data->map[data->line - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->line)
	{
		if (data->map[i][0] != '1' || data->map[i][data->column - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map(t_data *data)
{
	if (check_rect(data))
		return (1);
	if (check_valid(data))
		return (1);
	if (check_missing(data))
	{
		ft_putstr_fd("Missing P/C/E\n", 1);
		return (1);
	}
	if (data->p_status > 1 || data->e_status > 1)
	{
		ft_putstr_fd("More than 1 P/E\n", 1);
		return (1);
	}
	if (check_wall(data))
	{
		ft_putstr_fd("Not surrounded by wall\n", 1);
		return (1);
	}
	if (ft_is_reachable(data))
	{
		ft_putstr_fd("Unreachable C/E\n", 1);
		return (1);
	}
	return (0);
}

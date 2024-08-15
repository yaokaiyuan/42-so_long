/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:55:18 by paradari          #+#    #+#             */
/*   Updated: 2024/07/28 17:55:20 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clear_img(t_data *data)
{
	if (data->tile)
		mlx_destroy_image(data->mlx, data->tile);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->collect)
		mlx_destroy_image(data->mlx, data->collect);
	if (data->player_1)
		mlx_destroy_image(data->mlx, data->player_1);
	if (data->player_2)
		mlx_destroy_image(data->mlx, data->player_2);
	if (data->player_4)
		mlx_destroy_image(data->mlx, data->player_3);
	if (data->player_4)
		mlx_destroy_image(data->mlx, data->player_4);
	if (data->exit_locked)
		mlx_destroy_image(data->mlx, data->exit_locked);
	if (data->exit_unlocked)
		mlx_destroy_image(data->mlx, data->exit_unlocked);
}

void	ft_clear_mlx(t_data *data)
{
	ft_clear_img(data);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	data->player = NULL;
	data->exit = NULL;
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free (data->mlx);
	}
}

int	ft_destroy_2(t_data *data)
{
	ft_free_map(data->map);
	ft_free_map(data->tmp);
	free(data);
	exit(0);
}

int	ft_destroy(t_data *data)
{
	ft_free_map(data->map);
	ft_free_map(data->tmp);
	ft_clear_mlx(data);
	free(data);
	exit(0);
}

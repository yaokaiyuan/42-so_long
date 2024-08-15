/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:55:28 by paradari          #+#    #+#             */
/*   Updated: 2024/07/28 02:51:57 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->pos_x = x;
				data->pos_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->width, data->height,
			"Game Start\n");
	if (!data->window)
		free(data->window);
}

void	ft_init_image(t_data *data)
{
	data->tile = mlx_xpm_file_to_image(data->mlx, TILE, &data->isize,
			&data->isize);
	data->wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->isize,
			&data->isize);
	data->collect = mlx_xpm_file_to_image(data->mlx, COLLECT, &data->isize,
			&data->isize);
	data->player_1 = mlx_xpm_file_to_image(data->mlx, P1, &data->isize,
			&data->isize);
	data->player_2 = mlx_xpm_file_to_image(data->mlx, P2, &data->isize,
			&data->isize);
	data->player_3 = mlx_xpm_file_to_image(data->mlx, P3, &data->isize,
			&data->isize);
	data->player_4 = mlx_xpm_file_to_image(data->mlx, P4, &data->isize,
			&data->isize);
	data->exit_locked = mlx_xpm_file_to_image(data->mlx, EXIT_L, &data->isize,
			&data->isize);
	data->exit_unlocked = mlx_xpm_file_to_image(data->mlx, EXIT_U, &data->isize,
			&data->isize);
	data->player = data->player_1;
	data->exit = data->exit_locked;
}

void	ft_set_status(char c, t_data *data, int i, int j)
{
	if (c == 'P')
	{
		data->pos_x = j;
		data->pos_y = i;
		data->p_status++;
	}
	if (c == 'E')
	{
		data->exit_x = j;
		data->exit_y = i;
		data->e_status++;
	}
}

void	ft_init_game(t_data *data)
{
	ft_init_player(data);
	ft_init_mlx(data);
	ft_init_image(data);
}

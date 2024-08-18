/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:35:12 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/08/19 02:06:29 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->pos_x = x;
				data->pos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->width, data->height,
			"./so_long\n");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keybinds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:56:06 by paradari          #+#    #+#             */
/*   Updated: 2024/07/28 17:56:09 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_suit_up(t_data *data)
{
	if (data->p_status < 4)
	{
		data->p_status++;
		if (data->p_status == 1)
			data->player = data->player_2;
		if (data->p_status == 2)
			data->player = data->player_3;
		if (data->p_status == 3)
			data->player = data->player_4;
	}
}

void	ft_check_collect(t_data *data)
{
	if (data->collect_counter == data->c_status)
	{
		ft_suit_up(data);
		data->e_status = 0;
		data->exit = data->exit_unlocked;
		mlx_put_image_to_window(data->mlx, data->window, data->exit,
			data->exit_x * IMG_SIZE, data->exit_y * IMG_SIZE);
	}
}

void	ft_put_move(int move)
{
	char	*tmp;

	tmp = ft_itoa(move);
	ft_putstr_fd("Move : ", 1);
	ft_putstr_fd(tmp, 1);
	ft_putstr_fd("\n", 1);
	free (tmp);
}

void	ft_move(t_data *data, int new_x, int new_y)
{
	if (data->map[data->pos_y + new_y][data->pos_x + new_x] == '1')
		return ;
	data->move_counter++;
	ft_put_move(data->move_counter);
	if (data->map[data->pos_y][data->pos_x] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, data->exit,
			data->pos_x * IMG_SIZE, data->pos_y * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->tile,
			data->pos_x * IMG_SIZE, data->pos_y * IMG_SIZE);
	data->pos_x += new_x;
	data->pos_y += new_y;
	if (data->map[data->pos_y][data->pos_x] == 'C')
	{
		data->map[data->pos_y][data->pos_x] = '0';
		data->collect_counter++;
	}
	ft_check_collect(data);
	if ((data->map[data->pos_y][data->pos_x] == 'E') && data->e_status == 0)
		ft_destroy(data);
	mlx_put_image_to_window(data->mlx, data->window, data->player,
		data->pos_x * IMG_SIZE, data->pos_y * IMG_SIZE);
}

int	ft_keybinds(int key, t_data *data)
{
	if (key == ESC)
		ft_destroy(data);
	else if (key == W || key == UP)
		ft_move(data, 0, -1);
	else if (key == A || key == LEFT)
		ft_move(data, -1, 0);
	else if (key == S || key == DOWN)
		ft_move(data, 0, 1);
	else if (key == D || key == RIGHT)
		ft_move(data, 1, 0);
	return (0);
}

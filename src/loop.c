/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:54:55 by paradari          #+#    #+#             */
/*   Updated: 2024/07/28 13:15:33 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_loop(t_data *data)
{
	mlx_hook(data->window, KeyPress, KeyPressMask, &ft_keybinds, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask,
		&ft_destroy, data);
	mlx_loop(data->mlx);
}

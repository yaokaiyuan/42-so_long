/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:35:29 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/08/19 02:05:54 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_check(char *extension)
{
	if (extension[0] != '.' || extension[1] != 'b' || extension[2] != 'e'
		|| extension[3] != 'r' || !extension)
		return (1);
	return (0);
}

void	ft_check_input(char *av, int ac)
{
	int	len;

	len = 0;
	if (ac != 2)
	{
		ft_putstr_fd("Bad arguements Eg:./program_name map.ber\n", 1);
		exit (1);
	}
	len = ft_strlen(av);
	if (file_check(&av[len - 4]))
	{
		ft_putstr_fd("Map must be .ber file\n", 1);
		exit (1);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	ft_check_input(av[1], ac);
	data = ft_set_data(av[1], data);
	if (ft_check_map(data))
	{
		ft_destroy_2(data);
		return (1);
	}
	ft_init_game(data);
	ft_put_graphic(data);
	mlx_hook(data->window, KeyPress, KeyPressMask, &ft_keybinds, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask,
		&ft_destroy, data);
	mlx_loop(data->mlx);
	return (0);
}

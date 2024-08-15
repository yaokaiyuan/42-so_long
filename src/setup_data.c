/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <paradari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:55:28 by paradari          #+#    #+#             */
/*   Updated: 2024/07/28 14:04:45 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_line(char *file)
{
	int		fd;
	int		count;
	char	*buff;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error : Cannot open file\n", 1);
	else
	{
		buff = get_next_line(fd);
		while (buff)
		{
			count++;
			free(buff);
			buff = get_next_line(fd);
		}
		free(buff);
		close(fd);
	}
	return (count);
}

char	**ft_get_map(int fd, int row, int *column, char **map)
{
	char	*buff;

	buff = get_next_line(fd);
	while (buff)
	{
		*column = 0;
		map[row] = malloc((ft_strlen(buff) + 1) * sizeof(char));
		if (!map[row])
		{
			free(buff);
			return (NULL);
		}
		while (buff[*column] != '\0')
		{
			map[row][(*column)] = buff[*column];
			*column += 1;
		}
		map[row++][(*column)] = '\0';
		free (buff);
		buff = get_next_line(fd);
	}
	map[row] = NULL;
	close (fd);
	return (map);
}

void	ft_set_map(char *file, char **map, int *column)
{
	int		fd;
	int		row;

	row = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_putstr_fd("Error : Cannot open file\n", 1);
	else
	{
		map = ft_get_map(fd, row, column, map);
	}
}

void	ft_init_data(t_data *data)
{
	data->width = data->column * IMG_SIZE;
	data->height = data->line * IMG_SIZE;
	data->pos_x = 0;
	data->pos_y = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->move_counter = 0;
	data->collect_counter = 0;
	data->p_status = 0;
	data->c_status = 0;
	data->e_status = 0;
	data->isize = IMG_SIZE;
}

t_data	*ft_set_data(char *av, t_data *data)
{
	int	column_count;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	column_count = 0;
	data->line = ft_count_line(av);
	data->map = (char **)malloc((data->line + 1) * sizeof(char *));
	if (!(data->map))
		return (NULL);
	ft_set_map(av, data->map, &column_count);
	data->column = column_count;
	data->tmp = (char **)malloc((data->line + 1) * sizeof(char *));
	if (!(data->tmp))
		return (NULL);
	ft_set_map(av, data->tmp, &column_count);
	ft_init_data(data);
	return (data);
}

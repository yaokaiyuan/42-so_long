/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:35:37 by paradari          #+#    #+#             */
/*   Updated: 2023/12/13 15:35:39 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_collect_buff(char *current, char *buffer)
{
	char	*new;

	new = ft_strjoin(current, buffer);
	free(current);
	return (new);
}

char	*ft_read_all(char *current, int fd)
{
	char	*buffer;
	int		byte;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			ft_free_two(buffer, current);
			return (NULL);
		}
		if (byte == 0)
			break ;
		buffer[byte] = 0;
		current = ft_collect_buff(current, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (current);
}

char	*ft_collect_line(char *current)
{
	char	*line;
	int		i;
	int		j;

	if (!(*current))
		return (NULL);
	i = 0;
	while (current[i] && current[i] != '\n')
		i++;
	if (current[i] && current[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = current[j];
		j++;
	}
	line[j] = 0;
	return (line);
}

char	*ft_cut_oldline(char *current)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (current[i] && current[i] != '\n')
		i++;
	if (!current[i])
	{
		free(current);
		return (NULL);
	}
	if (current[i] && current[i] == '\n')
		i++;
	new = malloc(sizeof(char) * (ft_strlen(current) - i + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (current[i])
		new[j++] = current[i++];
	new[j] = 0;
	free(current);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*current;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!current)
		current = ft_calloc(1, 1);
	if (!current)
		return (NULL);
	current = ft_read_all(current, fd);
	if (!(current))
		return (NULL);
	line = ft_collect_line(current);
	current = ft_cut_oldline(current);
	return (line);
}

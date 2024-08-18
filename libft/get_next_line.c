/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:33:19 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/08/19 00:22:14 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	characters[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX < fd)
		return (NULL);
	line = ft_strjoin(0, characters);
	if (ft_clean(characters) > 0)
		return (line);
	i = read(fd, characters, BUFFER_SIZE);
	if (i < 0)
	{
		free(line);
		return (NULL);
	}
	while (i > 0)
	{
		line = ft_strjoin(line, characters);
		if (ft_clean(characters) > 0)
			break ;
		i = read(fd, characters, BUFFER_SIZE);
	}
	return (line);
}

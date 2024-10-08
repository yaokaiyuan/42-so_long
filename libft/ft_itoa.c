/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:25:35 by ykai-yua          #+#    #+#             */
/*   Updated: 2024/08/18 21:25:43 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_countnum(int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	ft_getnum(unsigned int num, int muls)
{
	unsigned int	i;

	i = 1;
	while (muls > 1)
	{
		i *= 10;
		muls--;
	}
	return ('0' + ((num / i) % 10));
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*str;
	unsigned int	len;
	unsigned int	i;

	len = ft_countnum(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		num = n * -1;
	}
	else
		num = n;
	while (i < len)
	{
		str[i] = ft_getnum(num, len - i);
		i++;
	}
	str[i] = 0;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouzid <abbouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:54:55 by abbouzid          #+#    #+#             */
/*   Updated: 2021/01/28 08:02:01 by abbouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	count_mem(int n, int *len)
{
	long num;

	num = (long)n;
	*len = 0;
	if (n < 0)
	{
		*len += 1;
		num = -num;
	}
	if (num == 0)
	{
		*len += 1;
		return;
	}
	while (num > 0)
	{
		num = num / 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = (long)n;
	count_mem(n, &len);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	if (n < 0)
		num = -num;
	if (num == 0)
		str[len] = '0';
	while (num)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

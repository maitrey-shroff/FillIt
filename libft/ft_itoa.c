/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:29:07 by mashroff          #+#    #+#             */
/*   Updated: 2018/12/10 14:29:16 by mashroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		get_size(unsigned int n, int size)
{
	if (n == 0)
		return (size);
	size++;
	n = n / 10;
	return (get_size(n, size));
}

static	void	create_str(char *str, int size, int flag, unsigned int n)
{
	int		i;

	i = 0;
	if (flag)
	{
		*str = '-';
		i++;
	}
	while (size > i)
	{
		*(str + size - 1) = (n % 10) + '0';
		n = n / 10;
		size--;
	}
}

char			*ft_itoa(int n)
{
	unsigned int	res;
	int				flag;
	int				size;
	char			*new;

	flag = 0;
	if (n < 0)
	{
		flag = 1;
		res = n * (-1);
	}
	else
		res = n;
	size = get_size(res, 0);
	if (n == 0)
		size = 1;
	new = (char*)malloc((size + flag + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[size + flag] = '\0';
	create_str(new, size + flag, flag, res);
	return (new);
}

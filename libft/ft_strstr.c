/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:48:39 by mashroff          #+#    #+#             */
/*   Updated: 2018/12/10 15:48:48 by mashroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_substr(const char *b, const char *little)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (*b != '\0' && *(little + j) != '\0')
	{
		if (*(little + j) == *b)
		{
			if (*(little + j + 1) == '\0')
				return ((char*)b - j);
			b++;
			j++;
			flag = 1;
		}
		else
		{
			j = 0;
			if (!flag)
				b++;
			flag = 0;
		}
	}
	return (NULL);
}

char			*ft_strstr(const char *big, const char *little)
{
	char		*res;
	int			i;

	i = 0;
	if (*little == '\0')
		return ((char*)big);
	res = NULL;
	while (*(big + i) != '\0' && res == NULL)
	{
		res = ft_substr(big + i, little);
		i++;
	}
	return (res);
}

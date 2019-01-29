/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:29:55 by mashroff          #+#    #+#             */
/*   Updated: 2018/12/10 14:35:49 by mashroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	i = 0;
	while (i < n)
	{
		*(d + i) = *(s + i);
		if (*(s + i) == (char)c)
			return ((void*)&d[i + 1]);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:30:17 by mashroff          #+#    #+#             */
/*   Updated: 2018/12/10 14:31:13 by mashroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;
	char		cc;

	cc = c;
	i = 0;
	str = s;
	while (i < n)
	{
		if (*str == cc)
			return (void *)(str);
		str++;
		i++;
	}
	return (NULL);
}

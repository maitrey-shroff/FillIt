/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:38:10 by mashroff          #+#    #+#             */
/*   Updated: 2018/12/10 14:38:18 by mashroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	i = 0;
	if (src > dst)
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	else
		while (len > 0)
		{
			len--;
			*(d + len) = *(s + len);
		}
	return (dst);
}

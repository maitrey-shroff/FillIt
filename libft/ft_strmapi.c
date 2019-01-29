/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:22:09 by mashroff          #+#    #+#             */
/*   Updated: 2018/12/10 15:22:15 by mashroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s)
	{
		i = 0;
		res = (char*)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (res)
		{
			res[ft_strlen(s)] = '\0';
			while (*s != '\0')
			{
				*(res + i) = f(i, *s);
				i++;
				s++;
			}
		}
		else
			return (NULL);
		return (res);
	}
	return (NULL);
}

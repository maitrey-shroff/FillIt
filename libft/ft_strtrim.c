/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:49:18 by mashroff          #+#    #+#             */
/*   Updated: 2018/12/12 12:55:31 by mashroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	start = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while ((s[start] == ' ' || s[start] == '\t' || \
			s[start] == '\n') && s[start] != '\0')
		start++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') && end >= start)
		end--;
	new = malloc(sizeof(char) * (end - start + 2));
	if (new == NULL)
		return (NULL);
	while (start <= end)
	{
		new[i++] = s[start];
		start++;
	}
	new[i] = '\0';
	return (new);
}

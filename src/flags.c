/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirenpat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:39:12 by hirenpat          #+#    #+#             */
/*   Updated: 2019/02/15 21:39:13 by hirenpat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int	pass(t_tetris *t)
{
	print_grid(t->grid, t->grid_size);
	return (1);
}

int	fail(void)
{
	ft_putstr("error\n");
	return (0);
}

int	usage(void)
{
	ft_putstr("usage: ./fillit input_file\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:40:30 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/21 23:50:20 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moves_nbr(int index, int stack_nbr)
{
	int		moves;

	moves = 0;
	if (stack_nbr / 2 >= index)
		moves = index;
	else if (stack_nbr / 2 < index)
		moves = stack_nbr - index;
	return (moves);
}

int	shortest_option(t_struct *struc, int i)
{
	int		tmp;
	int		value;
	int		moves;
	int		supr;
	int		supr_i;

	supr = 0;
	moves = 1000;
	i = 0;
	while (i < struc->sb_nbr)
	{
		supr = closest_supr(struc, struc->b[i]);
		supr_i = get_index(struc->a, struc->sa_nbr, supr);
		tmp = get_moves_nbr(i, struc->sb_nbr)
			+ get_moves_nbr(supr_i, struc->sa_nbr);
		if (moves > tmp)
		{
			moves = tmp;
			value = struc->b[i];
		}
		i++;
	}
	return (value);
}

int	get_index(int *stack, int len, int value)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (stack[i] == value)
			return (i);
		i++;
	}
	return (-42);
}

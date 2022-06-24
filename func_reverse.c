/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:25:31 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 10:09:57 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_rra(t_struct *struc)
{
	int		tmp;
	int		i;
	int		c;

	c = struc->sa_nbr - 1;
	tmp = struc->a[struc->sa_nbr - 1];
	i = 0;
	while (i < c)
	{
		struc->a[c] = struc->a[c - 1];
		c--;
	}
	struc->a[0] = tmp;
	printf("rra\n");
}

void	func_rrb(t_struct *struc)
{
	int		tmp;
	int		i;
	int		c;

	c = struc->sb_nbr - 1;
	tmp = struc->b[struc->sb_nbr - 1];
	i = 0;
	while (i < c)
	{
		struc->b[c] = struc->b[c - 1];
		c--;
	}
	struc->b[0] = tmp;
	printf("rrb\n");
}

void	func_rra1(t_struct *struc)
{
	int		tmp;
	int		i;
	int		c;

	c = struc->sa_nbr - 1;
	tmp = struc->a[struc->sa_nbr - 1];
	i = 0;
	while (i < c)
	{
		struc->a[c] = struc->a[c - 1];
		c--;
	}
	struc->a[0] = tmp;
}

void	func_rrb1(t_struct *struc)
{
	int		tmp;
	int		i;
	int		c;

	c = struc->sb_nbr - 1;
	tmp = struc->b[struc->sb_nbr - 1];
	i = 0;
	while (i < c)
	{
		struc->b[c] = struc->b[c - 1];
		c--;
	}
	struc->b[0] = tmp;
}

void	func_rrr(t_struct *struc)
{
	func_rra1(struc);
	func_rrb1(struc);
	printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_num_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:52:01 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/21 23:50:47 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func1(t_struct *struc)
{
	int		b_n;
	int		a_supr;
	int		b_index;	
	int		a_index;

	b_n = shortest_option(struc, 0);
	b_index = get_index(struc->b, struc->sb_nbr, b_n);
	a_supr = closest_supr(struc, b_n);
	a_index = get_index(struc->a, struc->sa_nbr, a_supr);
	if (((struc->sb_nbr / 2) >= b_index) && ((struc->sa_nbr / 2) >= a_index))
	{
		while ((struc->b[0] != b_n) && (struc->a[0] != a_supr))
			func_rr(struc);
	}
	if (((struc->sb_nbr / 2) < b_index) && ((struc->sa_nbr / 2) < a_index))
	{
		while ((struc->b[0] != b_n) && (struc->a[0] != a_supr))
			func_rrr(struc);
	}
}

void	func2(t_struct *struc)
{
	int		b_n;
	int		a_supr;
	int		b_index;	
	int		a_index;

	b_n = shortest_option(struc, 0);
	b_index = get_index(struc->b, struc->sb_nbr, b_n);
	a_supr = closest_supr(struc, b_n);
	a_index = get_index(struc->a, struc->sa_nbr, a_supr);
	if ((struc->sa_nbr / 2) >= a_index)
	{
		while (struc->a[0] != a_supr)
		{
			func_ra(struc);
		}
	}
	if ((struc->sa_nbr / 2) < a_index)
	{
		while (struc->a[0] != a_supr)
			func_rra(struc);
	}
}

void	func3(t_struct *struc)
{
	int		b_n;
	int		a_supr;
	int		b_index;	
	int		a_index;

	b_n = shortest_option(struc, 0);
	b_index = get_index(struc->b, struc->sb_nbr, b_n);
	a_supr = closest_supr(struc, b_n);
	a_index = get_index(struc->a, struc->sa_nbr, a_supr);
	if ((struc->sb_nbr / 2) >= b_index)
	{
		while (struc->b[0] != b_n)
			func_rb(struc);
	}
	if ((struc->sb_nbr / 2) < b_index)
	{
		while (struc->b[0] != b_n)
			func_rrb(struc);
	}
}

void	bring_num_up(t_struct *struc)
{
	func1(struc);
	func2(struc);
	func3(struc);
}

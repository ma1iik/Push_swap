/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:37:27 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/21 20:48:50 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dec_st(t_struct *struc)
{
	int		i;

	i = 0;
	struc->sa_nbr = struc->ac;
	struc->sb_nbr = 0;
	struc->a = malloc(sizeof(int) * (struc->ac));
	struc->b = malloc(sizeof(int) * (struc->ac));
	while (i < struc->ac)
	{
		struc->a[i] = ft_atoi(struc->argvs[i]);
		i++;
	}
}

int	stack_sorted(t_struct *struc)
{
	int		i;

	i = 0;
	while (i < struc->sa_nbr - 1)
	{
		if (struc->a[i] > struc->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	minrange_alg2(t_struct *struc, int min, int max)
{
	if (max == struc->a[1] && min == struc->a[2])
	{
		func_rra(struc);
		return ;
	}
	if (max == struc->a[2] && min == struc->a[1])
	{
		func_sa(struc);
		return ;
	}
	if (max == struc->a[0] && min == struc->a[1])
	{
		func_ra(struc);
		return ;
	}
	else if (max == struc->a[0] && min == struc->a[2])
	{
		func_ra(struc);
		func_sa(struc);
	}
}

void	minrange_alg(t_struct *struc)
{
	int		min;
	int		max;

	min = find_min(struc->a, struc->sa_nbr);
	max = find_max(struc->a, struc->sa_nbr);
	if (min == struc->a[0] && max == struc->a[1])
	{
		func_rra(struc);
		func_sa(struc);
		return ;
	}
	minrange_alg2(struc, min, max);
}

int	closest_supr(t_struct *struc, int num)
{
	int		supr;
	int		i;

	i = 0;
	supr = 2147483647;
	while (i < struc->sa_nbr)
	{
		if (struc->a[i] > num && struc->a[i] < supr)
			supr = struc->a[i];
		i++;
	}
	return (supr);
}

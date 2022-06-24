/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:24:42 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 10:14:57 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	func_ra(t_struct *struc)
{
	int		tmp;
	int		i;

	tmp = struc->a[0];
	i = 0;
	while (i < struc->sa_nbr)
	{
		struc->a[i] = struc->a[i + 1];
		i++;
	}
	struc->a[i - 1] = tmp;
	printf("ra\n");
}

void	func_rb(t_struct *struc)
{
	int		tmp;
	int		i;

	tmp = struc->b[0];
	i = 0;
	while (i < struc->sb_nbr)
	{
		struc->b[i] = struc->b[i + 1];
		i++;
	}
	struc->b[i - 1] = tmp;
	printf("rb\n");
}

void	func_ra1(t_struct *struc)
{
	int		tmp;
	int		i;

	tmp = struc->a[0];
	i = 0;
	while (i < struc->sa_nbr)
	{
		struc->a[i] = struc->a[i + 1];
		i++;
	}
	struc->a[i - 1] = tmp;
}

void	func_rb1(t_struct *struc)
{
	int		tmp;
	int		i;

	tmp = struc->b[0];
	i = 0;
	while (i < struc->sb_nbr)
	{
		struc->b[i] = struc->b[i + 1];
		i++;
	}
	struc->b[i - 1] = tmp;
}

void	func_rr(t_struct *struc)
{
	func_ra1(struc);
	func_rb1(struc);
	printf("rr\n");
}

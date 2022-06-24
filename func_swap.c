/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:22:44 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 10:10:22 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	func_sa(t_struct *struc)
{
	int		tmp;

	tmp = struc->a[0];
	if (struc->sa_nbr < 2)
		return (0);
	struc->a[0] = struc->a[1];
	struc->a[1] = tmp;
	printf("sa\n");
	return (1);
}

int	func_sb(t_struct *struc)
{
	int		tmp;

	if (struc->sb_nbr < 2)
		return (0);
	tmp = struc->b[0];
	struc->b[0] = struc->b[1];
	struc->b[1] = tmp;
	printf("sb\n");
	return (1);
}

int	func_sa1(t_struct *struc)
{
	int		tmp;

	tmp = struc->a[0];
	if (struc->sa_nbr < 2)
		return (0);
	struc->a[0] = struc->a[1];
	struc->a[1] = tmp;
	return (1);
}

int	func_sb1(t_struct *struc)
{
	int		tmp;

	if (struc->sb_nbr < 2)
		return (0);
	tmp = struc->b[0];
	struc->b[0] = struc->b[1];
	struc->b[1] = tmp;
	return (1);
}

void	func_ss(t_struct *struc)
{
	func_sa1(struc);
	func_sb1(struc);
	printf("ss\n");
}

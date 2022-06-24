/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:10:37 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/21 19:32:23 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	func_pb(t_struct *struc)
{
	int		i;
	int		c;

	i = 0;
	if (struc->sa_nbr == 0)
		return (0);
	if (struc->sb_nbr > 0)
	{
		c = struc->sb_nbr;
		while (i < c)
		{
			struc->b[c] = struc->b[c - 1];
			c--;
		}
	}
	struc->b[0] = struc->a[0];
	struc->sb_nbr++;
	while (i < struc->sa_nbr)
	{
		struc->a[i] = struc->a[i + 1];
		i++;
	}
	struc->sa_nbr--;
	printf("pb\n");
	return (0);
}

int	func_pa(t_struct *struc)
{
	int		i;
	int		c;

	i = 0;
	if (struc->sb_nbr == 0)
		return (0);
	if (struc->sa_nbr > 0)
	{
		c = struc->sa_nbr;
		while (i < c)
		{
			struc->a[c] = struc->a[c - 1];
			c--;
		}
	}
	struc->a[0] = struc->b[0];
	struc->sa_nbr++;
	while (i < struc->sb_nbr)
	{
		struc->b[i] = struc->b[i + 1];
		i++;
	}
	struc->sb_nbr--;
	printf("pa\n");
	return (0);
}

int	func_pb1(t_struct *struc)
{
	int		i;
	int		c;

	i = 0;
	if (struc->sa_nbr == 0)
		return (0);
	if (struc->sb_nbr > 0)
	{
		c = struc->sb_nbr;
		while (i < c)
		{
			struc->b[c] = struc->b[c - 1];
			c--;
		}
	}
	struc->b[0] = struc->a[0];
	struc->sb_nbr++;
	while (i < struc->sa_nbr)
	{
		struc->a[i] = struc->a[i + 1];
		i++;
	}
	struc->sa_nbr--;
	return (0);
}

int	func_pa1(t_struct *struc)
{
	int		i;
	int		c;

	i = 0;
	if (struc->sb_nbr == 0)
		return (0);
	if (struc->sa_nbr > 0)
	{
		c = struc->sa_nbr;
		while (i < c)
		{
			struc->a[c] = struc->a[c - 1];
			c--;
		}
	}
	struc->a[0] = struc->b[0];
	struc->sa_nbr++;
	while (i < struc->sb_nbr)
	{
		struc->b[i] = struc->b[i + 1];
		i++;
	}
	struc->sb_nbr--;
	return (0);
}

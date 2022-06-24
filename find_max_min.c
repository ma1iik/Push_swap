/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:22:24 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/17 18:08:42 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int *list, int max_nbr)
{
	int		i;
	int		max;

	i = 0;
	max = -2147483647;
	while (i < max_nbr)
	{
		if (max < list[i])
			max = list[i];
		i++;
	}
	return (max);
}

int	find_min(int *list, int max_nbr)
{
	int		i;
	int		min;

	i = 0;
	min = 2147483647;
	while (i < max_nbr)
	{
		if (min > list[i])
			min = list[i];
		i++;
	}
	return (min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:49:19 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/23 15:47:23 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_msg(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

int	ft_atoi(const char *str)
{
	long long int	a;
	int				i;
	int				b;

	a = 0;
	b = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b = b * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - 48);
		i++;
		if (a > 2147483647 || a < -2147483648)
			error_msg();
	}
	return (a * b);
}

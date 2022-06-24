/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:18:06 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 16:13:49 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_base_hex(unsigned long long n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n > 15)
	{
		i += ft_base_hex(n / 16);
		i += ft_putchar(base[n % 16]);
	}
	else
	{
		ft_putchar(base[n]);
		i++;
	}
	return (i);
}

int	ft_base_hexbig(unsigned int n)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	if (n > 15)
	{
		i += ft_base_hexbig(n / 16);
		ft_putchar(base[n % 16]);
		i++;
	}
	else
	{
		ft_putchar(base[n]);
		i++;
	}
	return (i);
}

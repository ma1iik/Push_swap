/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:33:06 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 16:13:40 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int		i;

	i = -1;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{	
		i += ft_putchar('-');
		i += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	return (i);
}

int	ft_putnbrunsigned(unsigned int n)
{
	int		i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbrunsigned(n / 10);
		i += ft_putnbrunsigned(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long long ptr)
{
	int				count;

	count = 0;
	if (ptr == 0)
		count += ft_putstr("0x0");
	else if (ptr)
	{
		count += ft_putstr("0x");
		count += ft_base_hex(ptr);
	}
	return (count);
}

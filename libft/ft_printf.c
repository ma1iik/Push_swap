/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misrailo <misrailo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:55:35 by misrailo          #+#    #+#             */
/*   Updated: 2022/06/22 16:13:55 by misrailo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(va_list ap, char c)
{
	int		leng;

	leng = 0;
	if (c == 's')
		leng += ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
		leng += ft_putnbr(va_arg(ap, int));
	else if (c == 'c')
		leng += ft_putchar(va_arg(ap, int));
	else if (c == 'p')
		leng += ft_putptr(va_arg(ap, unsigned long long));
	else if (c == 'i')
		leng += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		leng += ft_putnbrunsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
		leng += ft_base_hex(va_arg(ap, unsigned int));
	else if (c == 'X')
		leng += ft_base_hexbig(va_arg(ap, unsigned int));
	return (leng);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			len;
	va_list		ap;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%' || (str[i] == '%' && str[i +1] == '%'))
		{
			len += ft_putchar(str[i]);
			if (str[i] == '%')
				i++;
			i++;
		}
		else if (str[i] == '%')
		{
			i++;
			len += ft_formats(ap, str[i]);
			i++;
		}
	}
	va_end(ap);
	return (len);
}

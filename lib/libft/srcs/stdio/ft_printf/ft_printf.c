/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkara2 <tkara2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:00:59 by tkara2            #+#    #+#             */
/*   Updated: 2024/06/16 22:37:45 by tkara2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/libft.h"

static int	ft_format_checker(char format, va_list args)
{
	int						count;
	unsigned long long int	ptr;

	count = 0;
	if (format == 'c')
		count += ft_pf_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_pf_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_pf_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_pf_putnbr_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_pf_putnbr_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
	{
		ptr = va_arg(args, unsigned long long int);
		if (ptr)
			count += ft_pf_putstr("0x");
		count += ft_pf_putaddr(ptr);
	}
	else if (format == '%')
		count += ft_pf_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		return_value;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	return_value = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			return_value += ft_format_checker(format[i + 1], args);
			i++;
		}
		else
			return_value += ft_pf_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (return_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:55:38 by vzeybek           #+#    #+#             */
/*   Updated: 2025/06/17 18:55:38 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(int c)
{
	write(1, &c, 1);
	return (1);
}

static int	format_specifiers(const char *format, int i, va_list *args)
{
	int	char_count;

	char_count = 0;
	if (format[i + 1] == 'c')
		char_count += ft_print_chr(va_arg(*args, int));
	else if (format[i + 1] == 's')
		char_count += ft_print_str(va_arg(*args, char *));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		char_count += ft_print_nbr(va_arg(*args, int));
	else if (format[i + 1] == 'x')
		char_count += ft_print_hex(va_arg(*args, unsigned int), BASE);
	else if (format[i + 1] == 'X')
		char_count += ft_print_hex(va_arg(*args, unsigned int), BASE_BIG);
	else if (format[i + 1] == 'p')
		char_count += ft_print_ptr(va_arg(*args, void *));
	else if (format[i + 1] == 'u')
		char_count += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format[i + 1] == '%')
		char_count += write(1, "%", 1);
	else
	{
		write(1, &format[i], 1);
		char_count++;
	}
	return (char_count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		char_count;

	i = 0;
	char_count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			char_count += format_specifiers(format, i, &args);
			i += 2;
		}
		else
		{
			write (1, &format[i], 1);
			i++;
			char_count++;
		}
	}
	va_end(args);
	return (char_count);
}

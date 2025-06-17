/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:55:44 by vzeybek           #+#    #+#             */
/*   Updated: 2025/06/17 19:51:11 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	return (i);
}

int	ft_print_nbr(int n)
{
	int		i;
	char	*s;

	ft_putnbr_fd(n, 1);
	s = ft_itoa(n);
	if (!s)
		return (0);
	i = ft_strlen(s);
	free(s);
	return (i);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	count++;
	return (count);
}

int	ft_print_hex(unsigned long long num, char *base_value)
{
	char	result;
	int		i;

	i = 0;
	if (num >= 16)
		i += ft_print_hex(num / 16, base_value);
	result = base_value[num % 16];
	write(1, &result, 1);
	i++;
	return (i);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	num;
	int					count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	num = (unsigned long long)ptr;
	write(1, "0x", 2);
	count = 2;
	count += ft_print_hex(num, "0123456789abcdef");
	return (count);
}

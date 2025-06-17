/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeybek <vzeybek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:55:41 by vzeybek           #+#    #+#             */
/*   Updated: 2025/06/17 18:55:41 by vzeybek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define BASE "0123456789abcdef"
# define BASE_BIG "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	ft_print_chr(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_ptr(void *ptr);
int	ft_print_hex(unsigned long long num, char *base_value);

#endif
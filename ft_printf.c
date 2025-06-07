#include <stdarg.h>
#include "./libft/libft.h"
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbru(unsigned int num)
{
	char result;
	if (num > 9)
	{
		ft_putnbru(num/10);
	}
	result = num % 10 + '0';
	write(1, &result, 1);
}

void	ft_print_ptr(void *ptr)
{
	unsigned long long 	num;

	num = (unsigned long long)ptr;
	write(1, "0x", 2);
	ft_print_hex(num);
}

static int	format_specifiers(const char *format, int i, va_list *args)
{

	if (format[i + 1] == 'c')
		ft_putchar(va_arg(*args, long));
	else if (format[i + 1] == 's')
		ft_putstr_fd(va_arg(*args, char *), 1);
	else if (format[i + 1] == 'd')
		ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format[i + 1] == 'i')
		ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format[i + 1] == 'x')
		ft_print_hex(va_arg(*args, unsigned int));
	else if (format[i + 1] == 'X')
		ft_print_hex_big(va_arg(*args, unsigned int));
	else if (format[i + 1] == 'p')
		ft_print_ptr(va_arg(*args, void *));
	else if (format[i + 1] == 'u')
		ft_putnbru(va_arg(*args ,unsigned int));
	else if (format[i + 1] == '%')
		write(1, "%%", 1); 
	return (2);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i += format_specifiers(format, i, &args);
		}
		else 
		{
			write (1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (i);
}

#include <stdio.h>

int	main()
{
	// char character = 'f';
	// int integer = -5420000;
	// char	*string = "selam";
	// unsigned int unsigned_int = 4294967295;
	// int	num = 255;
	// ft_printf("%c %s %d %u %% \n", character, string, integer, unsigned_int);

	// int num = 320;

    // printf("%%x     : %x\n", num);    // ff
    // printf("%%X     : %X\n", num);    // FF
    // printf("%%#x    : %#x\n", num);   // 0xff
    // printf("%%#X    : %#X\n", num);   // 0XFF

	// ft_printf("num: %x\n", num);
	// ft_printf("num: %X", num);

	int x = 42;
	int y = 58;

	 
	int printf_number = printf("Adres: %p\n", &x);  // Örnek çıktı: 0x7ffeefbff5ac
	
	int ft_printf_number = ft_printf("%d\n%d\n%d\n%s\n", x, y, 5999, "selam");


	ft_printf("%d\n%d\n", printf_number, ft_printf_number);

}


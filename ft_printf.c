#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	putnbr(int	num)
{
	char result;
	if (num == INT_MIN || num == -2147483648)
	{
		write(1, "-2", 1);
		num = 147483648;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;		
	}
	if (num > 9)
	{
		putnbr(num/10);
	}
	result = num % 10 + '0';
	write(1, &result, 1);
}

void		putnbru(unsigned int num)
{
	char result;
	if (num > 9)
	{
		putnbr(num/10);
	}
	result = num % 10 + '0';
	write(1, &result, 1);
}

void	ft_print_hex(int	num)
{
	char	base[16] = "0123456789abcdef";
	char	result;

	if (num > 16)
		ft_print_hex(num / 16);
	result = base[num % 16];
	write(1, &result, 1);
}
void	ft_print_hex_big(int	num)
{
	char	base[16] = "0123456789ABCDEF";
	char	result;

	if (num > 16)
		ft_print_hex_big(num / 16);
	result = base[num % 16];
	write(1, &result, 1);
}

void	ft_print_ptr(void *ptr)
{
	unsigned long long 	num;

	num = (unsigned long long)ptr;
	write(1, "0x", 2);
	ft_print_hex(num);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	char	character;
	char	*string;
	int		integer;
	int		hex;
	int		hex2;
	unsigned int	u;
	void	*pointer;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			character = va_arg(args, int);
			write(1, &character, 1);
			i++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			string = malloc(strlen(string));
			if (!string)
				return (0);
				string = va_arg(args, char *);
			write(1, string, strlen(string));
			i++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			integer = va_arg(args, long);
			putnbr(integer);
			i++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'i')
		{
			integer = va_arg(args, long);
			putnbr(integer);
			i++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			hex = va_arg(args, long);
			ft_print_hex(hex);
			i++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			hex2 = va_arg(args, long);
			ft_print_hex_big(hex2);
			i++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			pointer = va_arg(args, void *);
			ft_print_ptr(pointer);
			i++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 'u')
		{
			u = va_arg(args, unsigned int);
			putnbru(u);
			i++;
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			character = '%';
			write(1, &character, 1);
			i++;
			i++;
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
	printf("Adres: %p\n", &x);  // Örnek çıktı: 0x7ffeefbff5ac
	ft_printf("%p", &x);

}


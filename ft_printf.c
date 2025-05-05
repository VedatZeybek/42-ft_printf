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

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	char	character;
	char	*string;
	int		integer;
	
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			character = va_arg(args, int);
			write(1, &character, 1);
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
		}
		else if (format[i] == '%' && format[i + 1] == 'd')
		{
			integer = va_arg(args, long);
			putnbr(integer);
			i++;
		}
		else
			write (1, &format[i], 1);
			i++;
	}
	va_end(args);
	return (i);
}

#include <stdio.h>

int	main()
{
	char character = 'f';
	int integer = -5420000;
	char	*string = "selam";
	ft_printf("%c %s %d ", character, string, integer);
}

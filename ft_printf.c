#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	char	c;
	char	*s;
	
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			s = malloc(strlen(s));
			if (!s)
				return (0);
			s = va_arg(args, char *);
			write(1, s, strlen(s));
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
	int integer = 20;
	char	*string = "selam";
	ft_printf("%c %s %d ", character, string, integer);
}

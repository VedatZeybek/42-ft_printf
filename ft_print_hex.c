#include "ft_printf.h"

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

#include "ft_printf.h"

int ft_char(char c, t_flags *flags)
{
	int  length;

	length = 0;
	if (flags->minus == 1)
		ft_putchar(c);
	length = ft_set_spaces_nulls(flags->width, 1, 0);
	if (flags->minus == 0)
		ft_putchar(c);
	return (length + 1);
}
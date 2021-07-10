#include "ft_printf.h"

int ft_percent(t_flags *flags)
{
	int len;

	len = 0;
	if (flags->minus == 1)
		len = len + ft_putstroke("%", 1);
	len = len + ft_set_spaces_nulls(flags->width, 1, flags->zero);
	if (flags->minus == 0)
		len = len + ft_putstroke("%", 1);
	return (len);
}
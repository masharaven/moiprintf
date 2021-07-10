#include "ft_printf.h"

t_flags	*flag_width(va_list args, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->zero = 0;
		flags->minus = 1;
		flags->width *= -1;
	}
	return (flags);
}

t_flags	*flags_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
	return (flags);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

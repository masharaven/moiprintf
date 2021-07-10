#include "ft_printf.h"

t_flags	*flags_zero(t_flags *flags)
{
	flags->zero = 0;
	flags->width = 0;
	flags->dot = -1;
	flags->minus = 0;
	flags->star = 0;
	flags->type = 0;
	return (flags);
}

int	checkinlist(int c, char *str)
{
	int	len;

	len = 0;
	while (c != str[len] && str[len])
		len++;
	if (str[len] == 0)
		return (0);
	return (str[len]);
}

static int	parse_input(va_list	args, const char	*tutochki, t_flags *flags)
{
	int		length;
	int		i;

	length = 0;
	i = 0;
	while (tutochki[i])
	{
		flags_zero(flags);
		if (tutochki[i] != '%')
			length = length + ft_putchar(tutochki[i]);
		else if (tutochki[i] == '%' && tutochki[i + 1])
		{
			i++;
			i = parse_flags(tutochki, i, flags, args);
			if (checkinlist(tutochki[i], SPECIFIC))
				length = length + ft_cspdu((char) flags->type, flags, args);
			else
				length = length + ft_putchar(tutochki[i]);
		}
		i++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			length;
	t_flags		*flags;

	length = 0;
	flags = (t_flags *)malloc(sizeof(t_flags));
	flags_zero(flags);
	va_start(args, format);
	length = length + parse_input(args, format, flags);
	va_end(args);
	free(flags);
	return (length);
}

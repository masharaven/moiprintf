#include "ft_printf.h"

static int	ft_dot(const char *format, int i, t_flags *flags, va_list args)
{
	if (format[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (checkinlist(format[i], "0123456789"))
			flags->dot = format[i++] - '0' + (flags->dot * 10);
	}
	return (i);
}

static t_flags	*ft_flags(const char c, t_flags *flags, va_list args)
{
	if (c == '*')
		flags = flag_width(args, flags);
	if (c == '-')
		flags = flags_minus(flags);
	if (checkinlist(c, "0123456789"))
	{
		if (flags->star == 1)
			flags->width = 0;
		flags->width = (flags->width * 10) + c - '0';
	}
	return (flags);
}

int	parse_flags(const char *format, int i, t_flags *flags, va_list args)
{
	while (checkinlist(format[i], ALL_FLAGS))
	{
		if (format[i] == '0' && flags->minus == 0 && flags->width == 0)
		{
			flags->zero = 1;
			i++;
			continue ;
		}
		if (format[i] == '.')
			i = ft_dot(format, ++i, flags, args);
		flags = ft_flags(format[i], flags, args);
		if (checkinlist(format[i], SPECIFIC))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}


int	ft_cspdu(int c, t_flags *flags, va_list args)
{
	int	length;

	length = 0;
    if (flags->dot >= 0)
        flags->zero = 0;
	if (c == 'c')
		length = ft_char(va_arg(args, int), flags);
	if (c == 's')
	    length = ft_string(va_arg(args, char *), flags);
	else if (c == 'p')
		length = ft_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		length = ft_digit(va_arg(args, int), flags);
	else if (c == 'u')
		length = ft_unsint(va_arg(args, unsigned int), flags);
	else if (c == 'x')
		length = length + ft_hex_lowup(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		length = length +  ft_hex_lowup(va_arg(args, unsigned int), 0, flags); 
	else if (c == '%')
		length = length + ft_percent(flags);
	return (length);
}
#include "ft_printf.h"

static int if_minus(t_flags *flags)
{
	int len;

	len = 0;
	len = len + ft_putstroke("0x", 2);
	len = len + ft_set_spaces_nulls(flags->width, 0, 0);
	return (len);
}

static int	ft_pointer_minus(char *point, t_flags *flags)
{
	int len;

	len = 0;
	len = len + ft_putstroke("0x", 2);
	if (flags->dot > -1)
	{
		len = len + ft_set_spaces_nulls(flags->dot, ft_strlen(point), 1);
		len = len + ft_putstroke(point, flags->dot);
	}
	else
		len = len + ft_putstroke(point, ft_strlen(point));
	return (len);
}

int ft_pointer(unsigned long long cifra, t_flags *flags)
{
	int		len;
	char	*point;

	len = 0;
	if (cifra == 0 && flags->dot == 0)
	{
		flags->width = flags->width - 2;
		if (flags->width > 2 && flags->minus == 1)
			return (len = len + if_minus(flags));
		len = len + ft_set_spaces_nulls(flags->width, 0, 0);
		len = len + ft_putstroke("0x", 2);
		return (len);
	}
	point = ft_unpack_to_hex(cifra, 16);
	point = ft_tolower(point);
	if (flags->dot < ft_strlen(point))
		flags->dot = ft_strlen(point);
	if (flags->minus == 1)
		len = len + ft_pointer_minus(point, flags);
	len = len + ft_set_spaces_nulls(flags->width, ft_strlen(point) + 2, 0);
	if (flags->minus == 0)
		len = len + ft_pointer_minus(point, flags);
	free (point);
	return (len);
}
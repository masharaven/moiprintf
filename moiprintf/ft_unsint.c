#include "ft_printf.h"

static int	ft_subfunction(char *nbr, t_flags *flags, int len)
{
	len = 0;
	if (flags->dot >= 0)
		len += ft_set_spaces_nulls(flags->dot, ft_strlen(nbr), 1);
	while (*nbr)
	{
		write(1, &*nbr++, 1);
		len++;
	}
	return (len);
}

static int	print_unsigned(char *nbr, t_flags *flags, int len)
{
	if (flags->minus == 1)
		len += ft_subfunction(nbr, flags, len);
	if (flags->dot >= 0 && flags->dot < ft_strlen(nbr))
		flags->dot = ft_strlen(nbr);
	if (flags->dot >= 0)
	{
		flags->width -= flags->dot;
		len += ft_set_spaces_nulls(flags->width, 0, 0);
	}
	else
		len += ft_set_spaces_nulls(flags->width, ft_strlen(nbr), flags->zero);
	if (flags->minus == 0)
		len += ft_subfunction(nbr, flags, len);
	return (len);
}

int	ft_unsint(unsigned int i, t_flags *flags)
{
	char	*nbr;
	int		len;

	len = 0;
	if (flags->dot == 0 && i == 0)
	{
		len += ft_set_spaces_nulls(flags->width, 0, 0);
		return (len);
	}
	nbr = ft_uint_itoa(i);
	len += print_unsigned(nbr, flags, len);
	free (nbr);
	return (len);
}

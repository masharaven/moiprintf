#include "ft_printf.h"

/*static int	left_convertation(char *num, t_flags *flags, int len)
{
	len = 0;
	if (flags->dot >= 0)
		len = len + ft_set_spaces_nulls(flags->width, ft_strlen(num), 1);
	while (*num)
	{
		write(1, &*num++, 1);
		len++;
	}
	return (len);
}

static int put_na_print(char *num, t_flagss *flags, int len)
{
	if (flags->minus == 1)
		len = len + left_convertation(num, flags, len);
	if (flags->dot >= 0 && ft_strlen(num) > flags->dot)
		flags->dot = ft_strlen(num);
	if (flags->dot >= 0)
	{
		flags->width = flags->width - flags->dot;
		len = len + ft_set_spaces_nulls(flags->width, 0, 0);
	}
	else
		len = len + ft_set_spaces_nulls(flags->width, ft_strlen(num), flags->zero);
	if (flags->minus == 0)
		len = left_convertation(num, flags, len);
	return (len);

}

int ft_unsint(unsigned int d, t_flagss *flags)
{
	int length;
	char *num;

	length = 0;
	if (flags->dot == 0 && d == 0)
	{
		length = ft_set_spaces_nulls(flags->dot, 0, 0);
		return (length);
	}
	num = ft_uint_itoa(d);
	length = length + put_na_print(num, flags, length);
	free(num);
	return (length);
}*/


static int	ft_subfunction(char *nbr, t_flags *flags, int len)
{
	len = 0;
	if (flags->dot >= 0)
		len += ft_set_spaces_nulls(flags->dot, ft_strlen(nbr),1);
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
		len += ft_set_spaces_nulls(flags->width,  ft_strlen(nbr), flags->zero);
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
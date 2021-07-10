#include "ft_printf.h"

static int	sub_print_vot(char *vot, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->dot >= 0)
		i += ft_set_spaces_nulls(flags->dot - 1, ft_strlen(vot) - 1, 1);
	i += ft_putstroke(vot, ft_strlen(vot));
	return (i);
}

static int	print_vot(char *vot, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->minus == 1)
		i += sub_print_vot(vot, flags);
	if (flags->dot >= 0 && flags->dot < ft_strlen(vot))
		flags->dot = ft_strlen(vot);
	if (flags->dot >= 0)
	{
		flags->width -= flags->dot;
		i += ft_set_spaces_nulls(flags->width, 0, 0);
	}
	else
		i += ft_set_spaces_nulls(flags->width, ft_strlen(vot), flags->zero);
	if (flags->minus == 0)
		i += sub_print_vot(vot, flags);
	return (i);
}

int	ft_hex_lowup(unsigned int nbr, int i, t_flags *flags)
{
	char	*vot;
	int		ret;

	ret = 0;
	if (flags->dot == 0 && nbr == 0)
	{
		ret += ft_set_spaces_nulls(flags->width, 0, 0);
		return (ret);
	}
	vot = ft_unpack_to_hex((unsigned long long) nbr, 16);
	if (i == 1)
		vot = ft_tolower(vot);
	ret += print_vot(vot, flags);
	free (vot);
	return (ret);
}

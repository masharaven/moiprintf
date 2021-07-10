#include "ft_printf.h"
int	to_set_spacefor_min(char *s, t_flags *flags, int len)
{
	int	i;
	int	dot;

	len = 0;
	i = 0;
	dot = flags->dot;
	if (flags->dot >= 0)
		len += ft_set_spaces_nulls(flags->dot, ft_strlen(s), 0);
	else
		dot = ft_strlen(s);
	while (s[i] && i < dot)
		write(1, &s[i++], 1);
	len += i;
	return (len);
}

int	ft_string(char *str, t_flags *flags)
{
	int	length;

	length = 0;
	if (!str)
		str = "(null)";
	if (flags->dot >= 0 && ft_strlen(str) < flags->dot)
		flags->dot = ft_strlen(str);
	if (flags->minus == 1)
		length = length + to_set_spacefor_min(str, flags, length);
	if (flags->dot >= 0)
		length = length + ft_set_spaces_nulls(flags->width, flags->dot, \
		flags->zero);
	else
		length = length + ft_set_spaces_nulls(flags->width, ft_strlen(str), \
		flags->zero);
	if (flags->minus == 0)
		length = length + to_set_spacefor_min(str, flags, length);
	return (length);
}

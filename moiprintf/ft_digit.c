#include "ft_printf.h"

static int	ft_the_last_print(char *num, t_flags *flags)
{
	int	i;

	i = 0;
	while (flags->zero && flags->width > 0)
	{
		ft_putchar ('0');
		flags->width--;
		i++;
	}
	while (*num)
	{
		ft_putchar(*num);
		num++;
		i++;
	}
	if (flags->minus)
	{
		while (flags->width > 0)
		{
			ft_putchar(' ');
			flags->width-- ;
			i++;
		}
	}
	return (i);
}

static int	ft_digit_flags(char *num, t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->dot > 0 && !flags->zero && (flags->width > flags->dot))
	{
		while (flags->dot > 0 && flags->width > 0)
		{
			ft_putchar('0');
			flags->width--;
			flags->dot--;
			i++;
		}
	}
	else if ((flags->dot > 0 && !flags->zero) || flags->width < flags->dot)
	{
		while (flags->dot > 0)
		{
			ft_putchar('0');
			flags->width--;
			flags->dot--;
			i++;
		}
	}
	i += ft_the_last_print(num, flags);
	return (i);
}

static int	flags_zero_min(t_flags *flags)
{
	int	i;

	i = 0;
	if (!flags->zero && !flags->minus)
	{
		while (flags->width > 0 && (flags->width > flags->dot))
		{
			ft_putchar(' ');
			flags->width-- ;
			i++;
		}
	}
	return (i);
}

int	ft_digit(int i, t_flags *flags)
{
	int		len;
	char	*put;
	char	*num;

	len = 0;
	num = ft_itoa(i);
	put = num;
	if (i == 0 && flags->dot == 0)
		num = "";
	flags->dot -= ft_strlen(num);
	flags->width -= ft_strlen(num);
	if (num[0] == '-')
		flags->dot++ ;
	len += flags_zero_min(flags);
	if (num[0] == '-')
	{
		ft_putchar('-');
		len++;
		num++;
	}
	len += ft_digit_flags(num, flags);
	free (put), put = NULL;
	return (len);
}

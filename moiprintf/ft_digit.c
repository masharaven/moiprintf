#include "ft_printf.h"

/*static int ft_the_last_print(char *num, t_flagss *flags)
{
	int len;

	len = 0;
	while (flags->dot && flags->width > 0)
	{
		ft_putchar ('0');
		flags->width--;
		len++;
	}
	while (*num)
	{
		ft_putchar(*num);
		num++;
		len++;
	}
	if (flags->minus)
	{
		while (flags->width > 0)
		{
			ft_putchar(' ');
			flags->width--;
			len++;
		}
	}
	return (len);
}

static int	ft_digit_flagss(char *num, t_flagss *flags)
{
	int len;

	len = 0;
	if (flags->dot > 0 && flags->zero == 0 && (flags->width > flags->dot))
	{
		while (flags->dot > 0 && flags->width > 0)
		{
			ft_putchar('0');
			flags->width--;
			flags->dot--;
			len++;		
		}
	}
	else if ((flags->dot > 0 && !flags->zero) || flags->width < flags->dot)
	{
		while (flags->dot > 0)
		{
			ft_putchar('0');
			flags->width--;
			flags->dot--;
			len++;
		}
	}
	len = len + ft_the_last_print(num, flags);
	return (len);
}

static int flags_zero_min(t_flagss *flags)
{
	int	len;

	len = 0;
	if (!flags->zero && !flags->minus)
	{
		while (flags->width > 0 && (flags->width > flags->dot))
		{
			ft_putchar(' ');
			flags->width--;
			len++;
		}
	}
	return (len);
}

int		ft_digit(int c, t_flagss *flags)
{
	int len;
	char *num;
	char *vrem;

	len = 0;
	num = ft_itoa(c);
	vrem = num;
	if (flags->dot == 0 && c == 0)
		num = "";
	flags->dot = flags->dot - ft_strlen(num);
	flags->width = flags->width - ft_strlen(num);
	if (num[0] == '-')
		flags->dot++;
	len += flags_zero_min(flags);
	if (num[0] == '-')
	{
		ft_putchar('-');
		len++;
		num++;
	}
	len = len + ft_digit_flagss(num, flags);
	free (vrem);
	return (len);
}*/

static	int	ft_print_int(char *nbr, t_flags *flags)
{
	int	i;

	i = 0;
	while (flags->zero && flags->width > 0)
	{
		ft_putchar ('0');
		flags->width--;
		i++;
	}
	while (*nbr)
	{
		ft_putchar(*nbr);
		nbr++;
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

static	int	ft_int_dot(char *nbr, t_flags *flags)
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
	i += ft_print_int(nbr, flags);
	return (i);
}

static int	ft_aligment(t_flags *flags)
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
	int		ret;
	char	*tmp;
	char	*nbr;

	ret = 0;
	nbr = ft_itoa(i);
	tmp = nbr;
	if (i == 0 && flags->dot == 0)
		nbr = "";
	flags->dot -= ft_strlen(nbr);
	flags->width -= ft_strlen(nbr);
	if (nbr[0] == '-')
		flags->dot++ ;
	ret += ft_aligment(flags);
	if (nbr[0] == '-')
	{
		ft_putchar('-');
		ret++;
		nbr++;
	}
	ret += ft_int_dot(nbr, flags);
	free (tmp);
	return (ret);
}

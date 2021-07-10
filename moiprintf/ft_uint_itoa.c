#include "ft_printf.h"

static int	ft_count_len(long c)
{
	int	len;

	len = 0;
	if (c < 0)
	{
		len++;
		c = c * (-1);
	}
	while (c > 0)
	{
		len++;
		c /= 10;
	}
	return (len);
}

static char	*ft_convert_char(char *str, long num, int len, int minus)
{
	if (num != 0)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		return (str = ft_strdup("0"));
	if (!str)
		return (0);
	if (num < 0)
		num = num * (-1);
	str[len] = '\0';
	while (--len > 0)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (minus == 1)
		str[0] = '-';
	else
		str[0] = (num % 10) + '0';
	return (str);
}

char	*ft_uint_itoa(unsigned int c)
{
	int		len;
	char	*put;
	long	num;
	int		min;

	num = c;
	put = 0;
	min = 0;
	if (num < 0)
		min++;
	len = ft_count_len(c);
	put = ft_convert_char(put, num, len, min);
	if (!put)
		return (0);
	return (put);
}

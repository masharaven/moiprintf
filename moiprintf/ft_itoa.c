#include "ft_printf.h"

static char	*add_minus(int flag, char *res)
{
	if (flag == 1)
	{
		res[0] = '-';
		return (res);
	}
	else
		return (res);
}

static int	len_nbr(int nbr)
{
	int		len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*res;
	int				flag;
	int				len;

	if (n < 0)
		flag = 1;
	else
		flag = 0;
	len = len_nbr(n);
	if (n < 0)
		n *= -1;
	nbr = n;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = nbr % 10 + 48;
		nbr = nbr / 10;
		len--;
	}
	res = add_minus(flag, res);
	return (res);
}

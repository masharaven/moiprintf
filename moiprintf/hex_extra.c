#include "ft_printf.h"
/*
static char	*ft_do(unsigned long long num, int dev, char *vot, int count)
{
	if (num / dev != 0)
	{
		vot[--count] = "0123456789abcdef"[num % dev];
		num /= dev;
	}
	vot[--count] = "0123456789abcdef"[num % dev];
	return (vot);
}

*/
static char	*ft_do(unsigned long long anum, int dev, char *vot, int i)
{
	while (anum != 0)
	{
		if ((anum % dev) < 10)
			vot[i - 1] = (anum % dev) + 48;
		else
			vot[i - 1] = (anum % dev) + 55;
		anum /= dev;
		i--;
	}
	return (vot);
}

char *ft_unpack_to_hex(unsigned long long num, int dev)
{
	int					count;
	char				*vot;
	unsigned long long	anum;


	count = 0;
	anum = num;
	if (anum == 0)
		return (ft_strdup("0"));
	while (num != 0)
	{
		num = num / dev;
		count++;
	}
	vot = (char *)malloc(sizeof(char) * (count + 1));
	if (!vot)
		return (0);
	vot[count] = '\0';
	vot = ft_do(anum, dev, vot, count);
	return (vot);
}

/*static char	*ft_dev(unsigned long long ull, int dev, char *ret, int i)
{
	while (ull != 0)
	{
		if ((ull % dev) < 10)
			ret[i - 1] = (ull % dev) + 48;
		else
			ret[i - 1] = (ull % dev) + 55;
		ull /= dev;
		i--;
	}
	return (ret);
}

char	*ft_unpack_to_hex(unsigned long long nbr, int dev)
{
	char				*ret;
	unsigned long long	ull;
	int					i;

	ret = 0;
	i = 0;
	ull = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		nbr /= dev;
		i++;
	}
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	ret[i] = 0;
	ret = ft_dev(ull, dev, ret, i);
	return (ret);
}*/

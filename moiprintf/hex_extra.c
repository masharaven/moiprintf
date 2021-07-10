#include "ft_printf.h"

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

char	*ft_unpack_to_hex(unsigned long long num, int dev)
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

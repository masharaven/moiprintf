#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		length;
	char	*dst;

	i = 0;
	length = ft_strlen(str);
	dst = (char *)malloc((length + 1) * sizeof(char));
	if (dst)
	{
		while (i <= length)
		{
			dst[i] = str[i];
			i++;
		}
		return (dst);
	}
	else
		return (NULL);
}

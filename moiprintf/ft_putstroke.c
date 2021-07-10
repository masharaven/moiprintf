#include "ft_printf.h"

int	ft_putstroke(char *s, int	flg_dot)
{
	int	len;

	len = 0;
	while (s[len] && len < flg_dot)
		write(1, &s[len++], 1);
	return (len);
}
#include "ft_printf.h"

int    ft_set_spaces_nulls(int flags, int amount, int zero)
{
	int length;
	
	length = 0;
	while (flags-- - amount > 0)
	{
		if (zero == 1)
			write(1, "0", 1);
		if (zero == 0)
			write(1, " ", 1);
		length++;
	}
	return (length);
}
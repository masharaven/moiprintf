#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef SPECIFIC
#  define SPECIFIC "cspdiuxX%"
# endif

# ifndef ALL_FLAGS
#  define ALL_FLAGS "cspdiuxX%-0123456789.*"
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>



typedef struct s_flags{
	int		width;
	int		minus;
	int		zero;
	int		star;
	int		type;
	int		dot;
}	t_flags;

int		ft_printf(const char *format, ...);
//new
int		checkinlist(int c, char *str);

int		ft_cspdu(int c, t_flags *flags, va_list args);
int		ft_char(char c, t_flags *flags);
int		ft_string(char *str, t_flags *flags);
int     ft_strlen(const char *s);
int		ft_pointer(unsigned long long cifra, t_flags *flags);
int		ft_digit(int c, t_flags *flags);
char    *ft_uint_itoa(unsigned int c);
int		ft_unsint(unsigned int d, t_flags *flags);
int		ft_hex_lowup(unsigned int num, int low_up, t_flags *flags);
int		ft_percent(t_flags *flags);
//flags
t_flags	*flag_width(va_list args, t_flags *flags);
t_flags	*flags_minus(t_flags *flags);
int		parse_flags(const char *format, int i, t_flags *flags, va_list args);
//funcs
int		to_set_spacefor_min(char *s, t_flags *flags, int len);
int		ft_putstroke(char *s, int	flg_dot);
int    ft_set_spaces_nulls(int flags, int amount, int zero);
//libft
char	*ft_tolower(char *str);
char	*ft_unpack_to_hex(unsigned long long nbr, int dev);
char	*ft_strdup(const char *str);
int		ft_putchar(int a);
char	*ft_itoa(int n);







#endif






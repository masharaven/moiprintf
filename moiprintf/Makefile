SRCS	= 	check_cspdu.c \
			check_flags.c \
			ft_char.c \
			ft_printf.c \
			libft.c \
			ft_set_spaces_nulls.c\
			ft_string.c\
			ft_pointer.c \
			ft_putstroke.c \
			hex_extra.c \
			ft_digit.c \
			ft_itoa.c \
			ft_unsint.c \
			ft_uint_itoa.c \
			ft_hex_lowup.c\
			ft_percent.c \
			
OBJS	=	$(SRCS:.c=.o)
CC		= 	gcc
RM		=	rm -rf
AR		=	ar rcs
CFLAGS	=	-Wall -Wextra -Werror -I.
NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS) ft_printf.h
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re 
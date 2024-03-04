NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = find_func.c \
		ft_putnbr_base.c \
		manage_char.c \
		manage_hexl.c \
		manage_hexu.c \
		manage_i_d.c \
		manage_percent.c \
		manage_ptr.c \
		manage_str.c \
		manage_uns.c \
		puts.c \
		ftprintf.c

OBJ = $(SRCS:.c=.o)

HEADER = utility_func.h

all : $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I . -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

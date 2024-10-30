NAME= libftprintf.a

LIBFT= libft

AR= ar -rcs

CC= cc
CFLAGS= -Wall -Werror -Wextra

SRC=		ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils_extra.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h libft.h
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $< -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL: all

.PHONY: all clean fclean re

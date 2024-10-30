# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 19:18:42 by rmunoz-c          #+#    #+#              #
#    Updated: 2024/10/30 20:28:33 by rmunoz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

LIBFT_DIR= libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_OBJ = $(LIBFT_DIR)/*.o

AR= ar -rcs

CC= cc
CFLAGS= -Wall -Werror -Wextra
RN= ranlib

SRC=		ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils_extra.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(AR) $(NAME) $(OBJ) $(LIBFT_OBJ)
	$(RN) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h libft.h
	$(CC) $(CFLAGS) -o $@ $< -c

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.DEFAULT_GOAL: all

.PHONY: all clean fclean re

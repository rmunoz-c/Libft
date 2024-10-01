# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 20:32:53 by rmunoz-c          #+#    #+#              #
#    Updated: 2024/09/30 22:40:49 by rmunoz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

AR= ar -rcs

CC= cc
CFLAGS= -Wall -Werror -Wextra

SRC=		ft_bzero.c \
			ft_strchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_atoi.c \
			ft_isascii.c \
			ft_isalnum.c \
			ft_striteri.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_isprint.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strdup.c \
			ft_calloc.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_memcpy.c \
			ft_strtrim.c \
			ft_putendl_fd.c \
			ft_strlcat.c \
			ft_memset.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_split.c \
			
SRC_BONUS=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJ= $(SRC:.c=.o) 
OBJ_BONUS= $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $< -c

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	@make SRC="$(SRC) $(SRC_BONUS)"

.DEFAULT_GOAL: all

.PHONY: all clean fclean re

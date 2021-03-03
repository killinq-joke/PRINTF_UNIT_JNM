# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 13:04:24 by trofidal          #+#    #+#              #
#    Updated: 2021/02/18 13:04:24 by trofidal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LDFLAGS=-L
LDLIBS=-lft
SRC = ft_printf_main.c ft_printf_flags.c

OBJ = $(SRC:.c=.o)
INC = ./inc/

$(NAME): $(OBJ)
				cp libft/libft.a $(NAME)
				ar -rcs $(NAME) $(OBJ)  

%.o: %.c
				$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
				$(RM) $(OBJ)

fclean: clean
				$(RM) $(NAME)

re: fclean all

.PHONY: clean clean

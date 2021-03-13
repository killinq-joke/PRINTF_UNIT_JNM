# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trofidal <trofidal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 13:04:24 by trofidal          #+#    #+#              #
#    Updated: 2021/03/12 10:21:27 by trofidal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LDFLAGS=-L
LDLIBS=-lft
SRC = 	ft_printf.c				\
		ft_get_char.c			\
		ft_get_content.c		\
		ft_get_float.c			\
		ft_get_int.c			\
		ft_get_ptr.c			\
		ft_get_str.c			\
		ft_is_convert.c			\
		ft_star_value.c			\
		ft_get_u.c				\
		ft_get_e.c				\
		ft_get_n.c				\
		ft_get_percent.c		\
		ft_flags_parser.c		\
		ft_get_flags_done.c		\
		ft_get_first_value.c	\
		ft_get_second_value.c	\
		ft_get_g.c

OBJ = $(SRC:.c=.o)
INC = ./inc/

$(NAME): $(OBJ)
				cp libft/libft.a $(NAME)
				ar -rcs $(NAME) $(OBJ)  

%.o: %.c
				$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

bonus : $(NAME)

clean:
				$(RM) $(OBJ)

fclean: clean
				$(RM) $(NAME)

re: fclean all

.PHONY: clean clean

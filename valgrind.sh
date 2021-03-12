#!/bin/bash

make fclean && make -s && make clean -s && gcc -Wall -Wextra -Werror -g ft_printf.c libftprintf.a && valgrind  --show-leak-kinds=all --leak-check=full --track-origins=yes -s ./a.out
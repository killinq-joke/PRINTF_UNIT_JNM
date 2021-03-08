#!/bin/bash

make -s && make clean -s && gcc -Wall -Wextra -Werror -g ft_printf.c libftprintf.a && valgrind --leak-check=full --track-origins=yes -s ./a.out
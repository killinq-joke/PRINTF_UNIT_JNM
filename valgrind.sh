#!/bin/bash

make && make clean && gcc -Wall -Wextra -Werror -g ft_printf.c libftprintf.a && valgrind --leak-check=full --track-origins=yes -s ./a.out
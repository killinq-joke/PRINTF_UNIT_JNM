#!/bin/bash

RED = '\033[0;31m'
GREEN = '\033[0;30m'

make && make clean && gcc ft_printf.c libftprintf.a 
echo $'----==== RESULTS ====----'
./a.out
echo -e "${RED}COUCOU"
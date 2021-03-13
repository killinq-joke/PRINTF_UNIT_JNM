#!/bin/bash

RED='\e[31m' # RED
GREEN='\e[32m' # GREEN
CYAN='\e[36m' # CYAN
DGREY='\e[90m' #DARK GREY
BLINK='\e[5m' # BLINK
YELW='\e[33m' #Yellow
UL='\e[4m'
EUL='\e[24m'
BOLD='\e[1m'
ENDBLINK='\e[25'
NC='\e[97m' # No Color
SPACER_START_EASY="${DGREY}▌                    ${YELW}${BOLD}${UL}▶▶ F T _ P R I N T F ◀◀${EUL}${LBLUE}                                  ${YELW}${BOLD}${UL}▶▶ E A S Y ◀◀${EUL}${DGREY}                    ▌${NC}"
SPACE_HEAD="${DGREY}▌                                                                                                              ▌${NC}"												
SPACER_KO="${DGREY}▌                                                   ${BOLD}${RED}▶▶ K O ◀◀${LBLUE}                                                 ${DGREY} ▌${NC}"
SPACER_OK="${DGREY}▌                                                   ${BOLD}${GREEN}▶▶ O K ◀◀${LBLUE}                                                  ${DGREY}▌${NC}"
SPACER_TOP="${DGREY}▛▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▜${NC}"
					
SPACER_BOT="${DGREY}▙▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▟${NC}"
${NC}
rm -rf output_to_diff
mkdir output_to_diff
gcc -Wall -Werror -Wextra -w ./mains/easy_main.c -D function="printf" -o ./out/real.out
./out/real.out >> output_to_diff/real_results.txt
make -C ../
cp ../libftprintf.a ./srcs/
gcc -Wall -Werror -Wextra -w ./mains/easy_main.c ./srcs/libftprintf.a -D function="ft_printf" -o ./out/fake.out
./out/fake.out >> output_to_diff/fake_results.txt

clear
echo -e "${SPACER_TOP}\n${SPACE_HEAD}\n${SPACER_START_EASY}\n${SPACE_HEAD}\n${SPACER_BOT}${NC}"

echo

test_numb=1
note=0
sed -n ${test_numb}p output_to_diff/real_results.txt >> printf.txt
if [ -s output_to_diff/fake_results.txt ] ; then
while [ -s printf.txt ]
do
	rm -f printf.txt ft.txt printf_r.txt ft_r.txt
	sed -n ${test_numb}p output_to_diff/real_results.txt >> printf.txt
	sed -n ${test_numb}p output_to_diff/fake_results.txt >> ft.txt
	if [ $test_numb -lt 10 ] ; then
		echo -n ""
	else
		echo -n ""
	fi
	DIFF=$(diff ft.txt printf.txt)
	if [ "$DIFF" == "" ] ; then
 		echo -ne "\033[0;32m \xE2\x9C\x94	\033[0m"
		let "note += 1"
	else
 		echo -ne "$test_numb : \033[0;31m x	\033[0m"
		echo "----------Test $test_numb : ----------" >> diff.txt
		sed -n ${test_numb}p output_to_diff/fake_results.txt >> diff.txt
		echo >> diff.txt
		echo "$DIFF" >> diff.txt
		echo >> diff.txt		
	fi
	let "j = $test_numb % 10"
	if [ $j -eq 0 ] ; then
		echo
	fi
	let "test_numb += 1"
done
echo
let "test_numb -= 1"
if [ $test_numb -eq $note ] ; then
 		echo -ne " \033[0;32m $note / $test_numb : On your way to test Medium  ! \033[0m \n" 

		echo -e "${SPACER_TOP}\n${SPACER_OK}\n${SPACER_BOT}${NC}\n"

	else
 		echo -ne "\033[0;31m $note / $test_numb : Some error occured, see results.log ! \033[0m \n"

		echo -e "${SPACER_TOP}\n${SPACER_KO}\n${SPACER_BOT}${NC}\n"
	fi
echo

else
	echo -e "\033[0;31m \xEA\x93\xA5                    \xEA\x93\xA5 \033[0m"
	echo -ne "\033[4;31m/!\\"
	echo -ne "\033[0m\033[0;31m Does Not Compile \033[0m"
	echo -e "\033[4;31m/!\\"
fi
echo

make -C srcs/ fclean &> /dev/null
cp diff.txt results/results.log
rm -rf ft.txt printf.txt diff.txt

#https://misc.flogisoft.com/bash/tip_colors_and_formatting
#https://en.wikipedia.org/wiki/Box-drawing_character
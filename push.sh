#!/bin/bash
RED='\033[0;31m' # RED
GREEN='\033[1;32m' # GREEN
NC='\033[0m' # No Color
SPACER="${RED}---===---${NC}"

# fullname="USER INPUT"
read -p "Commentaire pour le commit: " comment


printf "${SPACER} ${GREEN}RESULTS${NC} ${SPACER}\n\n\n"
    make fclean
    rm a.aout
    git add .
    git commit -m "${comment}"
    git push
printf "\n\n${SPACER} ${GREEN}END${NC} ${SPACER}\n"
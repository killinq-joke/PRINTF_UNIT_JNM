#!/bin/bash
RED='\033[0;31m' # RED
GREEN='\033[1;32m' # GREEN
NC='\033[0m' # No Color
SPACER="${RED}---===---${NC}"

# fullname="USER INPUT"
read -p "Commentaire pour le commit: " comment


printf "${SPACER} ${GREEN}RESULTS${NC} ${SPACER}\n"
    git add .
    git commit -m "${comment}"
    git push
    echo "Git add ${GREEN}OK"
    echo "Git commit ${GREEN}OK"
    echo "Git push ${GREEN}OK"
printf "${SPACER} ${GREEN}END${NC} ${SPACER}\n"
#!/bin/bash

RED = '\033[0;31m'
GREEN = '\033[0;31m'

# fullname="USER INPUT"
read -p "Commentaire pour le commit: " comment


echo $'----==== RESULTS ====----'
    git add .
    git commit -m "${comment}"
    git push
echo "Git add ${GREEN}OK"
echo "Git commit ${GREEN}OK"
echo "Git push ${GREEN}OK"
echo -e "${RED}COUCOU"
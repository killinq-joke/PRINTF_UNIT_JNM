# PRINTF_UNIT_JNM
Tester for ft_printf for school 42 project // junior-one // NotJustJoe //minikross //


Project

												---***---

bash easy # run sans valgrind # fonctions simple, tests basiques # sed les fonctions interdites (strcyp, strcat etc) #

bash medium # run sans valgrind # fonctions plus compliquées # sed les fonctions interdites (strcyp, strcat etc) # Returned Value are checked #

bash hard # run avec valgrind # fonctions complexes # sed les fonctions interdites (strcyp, strcat etc) #

												---***---

Si il y a une erreur print dans le diff sous cette forme :
===========================================================================================================\
=================================================== K O ===================================================|
===========================================================================================================/
TEST NUMBER 	: 	"78/100	"	
TYPE OF TEST	:	"%s		"
HAS	LEAKS		:	"NO		"						
TEST			:	"("%s", "hi i am a string")"
===========================================================================================================|
REAL PRINTF		 	:	|hi i am a string|
FT_PRINTF			:	|hi i am a stri**|
// * = error // FT_PRINTF = your result // REAL PRINTF = printf result //
===========================================================================================================/

If ok == Returns Nothing :

in the Shell :
---------------------------/
/>$bash easy.sh
Test Started for easy difficulty, valgrind is off
===========================================================================================================\
=================== F T _ P R I N T F ================================ E A S Y ============================|
===========================================================================================================/

========================\
====	Type : %s	====|
========================/

=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
 1  : OK | 2 : OK  | 3 : OK  | 4 : OK  | 5 : OK  | 6 : OK  | 7 : OK  | 8 : OK  | 9 : OK  | 10 : OK |
 11 : OK | 12 : OK | 13 : OK | 14 : OK | 15 : OK | 16 : OK | 17 : OK | 18 : OK | 19 : OK | 20 : OK |
 21 : OK | 22 : OK | 23 : OK | 24 : OK | 25 : OK | 26 : OK | 27 : OK | 28 : OK | 29 : OK | 30 : OK |
=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
Grade for %s : 100 / 100

========================\
====	Type : %d	====|
========================/

=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
 1 : OK  | 2 : OK  | 3 : OK  | 4 : OK  | 5 : OK  | 6 : OK  | 7 : OK  | 8 : OK  | 9 : OK  | 10 : OK |
 11 : OK | 12 : OK | 13 : OK | 14 : OK | 15 : OK | 16 : OK | 17 : OK | 18 : OK | 19 : OK | 20 : OK |
 21 : OK | 22 : OK | 23 : OK | 24 : OK | 25 : OK | 26 : OK | 27 : OK | 28 : OK | 29 : OK | 30 : OK |
=========|=========|=========|=========|=========|=========|=========|=========|=========|=========|
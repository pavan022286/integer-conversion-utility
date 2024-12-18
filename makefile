convert: main.c convert.c utils.c convert.h utils.h
	gcc -o convert main.c convert.c utils.c

ctest: main.c convert.c utils.c convert.h utils.h
	gcc --coverage -o ctest main.c convert.c utils.c 

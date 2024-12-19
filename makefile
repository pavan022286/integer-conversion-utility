convert: main.c convert.c utils.c convert.h utils.h
	gcc -o convert main.c convert.c utils.c

ctest: main.c convert.c utils.c convert.h utils.h
	gcc -o ctest --coverage main.c convert.c utils.c 

convert: convert.c
	gcc -o convert convert.c

ctest: convert.c
	gcc --coverage -o ctest convert.c

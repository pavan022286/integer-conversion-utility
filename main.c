#include <stdio.h>
#include "convert.h"
#include "utils.h"

#define DEFAULT_BASE 16  // sets the default base to hexadecimal

int main(int argc, char *argv[]) {
    int base = DEFAULT_BASE;
    long start = 0, finish = 0;
    
    //Analyze input
    if (parse_args(argc, argv, &base, &start, &finish) != 0) {
	fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers");
	return -1; //Show error 
    }
    // If range given, convert for range
    if (start != 0 || finish != 0) {
        for (long i = start; i <= finish; i++) {
            convert(i, base);
            printf("\n");
        }
    } 
    else { //Else just process each number
        long number;
        while (scanf("%ld", &number) != EOF) {
            convert(number, base);
            printf("\n");
        }
    }
    return 0; //Return success
}

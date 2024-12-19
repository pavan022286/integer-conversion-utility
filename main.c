/* Author: Pavan Patel
 * Program Info: Main funciton that calls convert and analyzes input
 *
 * */
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
	    if (i!=0) {
            	convert(i, base);
                printf("\n");
	    }
	    else {
	    	putchar('0');
                printf("\n");
	    }
        }
    } 
    else { //Else just process each number
        long number;
	int check=1;
        while (1) {
	    int check=scanf("%ld", &number);
	    if (check==EOF) {//ctrl + d entered, break and exit
		break;
	    }
	    if (check!=1) { // if scan does not scan long int, then print error
		fprintf(stderr,"Error: Non-long-int token encountered\n");
		return -1;
	    }
	    if (number==0) { //if number is 0, print 0
	    	putchar('0');
		printf("\n");
	    }
	    else { //otherwise call convert() to convert number
            	convert(number, base);
            	printf("\n");
	    }
        }
    }
    return 0; //Return success
}

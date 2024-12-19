/* Author: Pavan Patel
 * Program Info: Program parses command-line arguments and checks for errors
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_BASE 2 //define global constants
#define MAX_BASE 36

// Function to parse command-line arguments
int parse_args(int argc, char *argv[], int *base, long *start, long *finish) {
    *base = 16; // Default base is 16
    *start = 0;
    *finish = 0;
    
    if (argc == 2 && (strcmp(argv[1], "--help") == 0)) {
        printf("Program Background: Utility reads longs from standard input and converts them to a new radix (base)\nUsage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\nOptions:\n-b BASE Specify the base for conversion (default: 16)\n-r START FINISH Specify a range of numbers to convert\nSide Note: For bases higher than 10, capital letters A through Z should represent digit values 11 through 36.\n--help Show detailed help about the program usage.\n");
        return 0; // return 0 to show help message displayed
    }

    else if (argc < 2) { 
	return 0;  // Checks for arguments, if none, use default values 
    }

    else if (argc > 6) { //too many arguments, show error
	fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
	return 1;
    }
    
    else if (((strcmp(argv[1], "-b")) !=0) && (strcmp(argv[1], "-r") != 0)) { //if first argument not -b or -r or help, show error
        fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
        return 1;
    }

    else if ((strcmp(argv[1], "-b")) == 0) {
	if (argc!=6 && argc!=3) { //if -b is first argument but total arguments not 3 or 6, show error
	    fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
            return 1;
	}
	else if (argc == 3) {
	    *base = atoi(argv[2]);  // Convert the base from string to int
	    if (*base==0 || (strlen(argv[2])>1 && *base<10) || (strlen(argv[2])>2 && *base<37)) { //if any non-int as base, then show error
	        fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                return 1; //show error if base not an integer
	    }
	    else if (*base < MIN_BASE || *base > MAX_BASE) {
                fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                return 1; //show error if base not in acceptable range
	    }
	    argv += 2; //skips
	}
	else { //if 6 arguments
	    *base = atoi(argv[2]);  // Convert the base from string to int
            if (*base==0 || (strlen(argv[2])>1 && *base<10) || (strlen(argv[2])>2 && *base<37)) { //if any non-int as base, then show error
                fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                return 1; //show error if base not an integer
            }
            else if (*base < MIN_BASE || *base > MAX_BASE) {
                fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                return 1; //show error if base not in acceptable range
            }
	    else if (strcmp(argv[3], "-r") != 0) {
	        fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                return 1; //show error if 6 arguments and "-r" is not the 4th
	    }
	    //argv+=2 //skips
	    for (int i=0;i<strlen(argv[4]);i++) {
	        if (((argv[4][i])!="0" && (argv[4][i])!="1" && (argv[4][i])!="2" && (argv[4][i])!="3" && (argv[4][i])!="4" && (argv[4][i])!="5" && (argv[4][i])!="6" && (argv[4][i])!="7" && (argv[4][i])!="8" && (argv[4][i])!="9") && (i!=0 && (argv[4][i])!="-")) {
		    fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                    return 1; //show error if range not only integers
	        }   
	    }
	
	    for (int i=0;i<strlen(argv[5]);i++) {
	        if (((argv[5][i])!="0" && (argv[5][i])!="1" && (argv[5][i])!="2" && (argv[5][i])!="3" && (argv[5][i])!="4" && (argv[5][i])!="5" && (argv[5][i])!="6" && (argv[5][i])!="7" && (argv[5][i])!="8" && (argv[5][i])!="9") && (i!=0 && (argv[5][i])!="-")) {
		    fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                    return 1; //show error if range not only integers
                }
            }
	    *start = atol(argv[2]);   // Convert start to long type
            *finish = atol(argv[3]);  // Convert finish to long type
        }    
		
    }

    else { //if first argument is -r
        if (argc!=4) { //if -r is first argument but total arguments not 4, show error
            fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
            return 1;
        }
	for (int i=0;i<strlen(argv[2]);i++) {
	    if (((argv[2][i])!="0" && (argv[2][i])!="1" && (argv[2][i])!="2" && (argv[2][i])!="3" && (argv[2][i])!="4" && (argv[2][i])!="5" && (argv[2][i])!="6" && (argv[2][i])!="7" && (argv[2][i])!="8" && (argv[2][i])!="9") && (i!=0 && (argv[2][i])!="-")) {
		fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
		return 1; //show error if range not only integers
	    }
	}
	for (int i=0;i<strlen(argv[3]);i++) {                                                                        
	    if (((argv[3][i])!="0" && (argv[3][i])!="1" && (argv[3][i])!="2" && (argv[3][i])!="3" && (argv[3][i])!="4" && (argv[3][i])!="5" && (argv[3][i])!="6" && (argv[3][i])!="7" && (argv[3][i])!="8" && (argv[3][i])!="9") && (i!=0 && (argv[3][i])!="-")) {
		fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
		return 1; //show error if range not only integers
	    }
	}
        *start = atol(argv[2]);   // Convert start to long type
        *finish = atol(argv[3]);  // Convert finish to long type
    }

    return 0; //return 0 to indicate success
}
/*
     *base = atoi(argv[2]);  // Convert the base from string to int
            for (int i=0;i<strlen(argv[2]);i++) {
                if ((!isdigit(argv[2][i]))) {
                    fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                    return 1; //show error if base not an integer
                }
            }

    // Check for base entered
    if (strcmp(argv[1], "-b") == 0 && argc > 2) {
        *base = atoi(argv[2]);  // Convert the base from string to int
        if (*base < MIN_BASE || *base > MAX_BASE) {
            fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
	    return 1; //show error if base not in acceptable range
        }
        argv += 2;  // Skips
    }
    else if (strcmp(argv[1], "-b") != 0 && argc > 2) {
        fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
	return 1; //Show error
    }

    // Check for range entered
    if (argc > 4 && strcmp(argv[1], "-r") == 0) {
        *start = atol(argv[2]);   // Convert start to long type
        *finish = atol(argv[3]);  // Convert finish to long type
    }
    else if (argc > 4 && strcmp(argv[1], "-r") != 0) {
	fprintf(stderr,"Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
	return 1; //Show error
    }

    return 0;  // Return 0 to indicate success
}
*/

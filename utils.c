/* Author: Pavan Patel
 * Program Info: Program parses command-line arguments and checks for errors, also using a helper function
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_BASE 2 //define global constants
#define MAX_BASE 36

// helper function to check if a string represents a valid integer
int is_valid_integer(const char *str) {
    if (*str == '-') {
	str++; // skip leading negative sign, if any
    }
    if (*str == '\0') { 
        return 0;	// empties after sign is invalid
    }
    while (*str) {
        if (!isdigit(*str)) {
	    return 0;
	}
        str++;
    }
    return 1;
}

// Function to parse command-line arguments
int parse_args(int argc, char *argv[], int *base, long *start, long *finish) {
    *base = 16;  // Default base is 16
    *start = 0;
    *finish = 0;

    if (argc == 2 && strcmp(argv[1], "--help") == 0) { //if 1 argument and correct syntax for help, show help message (cleaner formatting)
        printf("Program Background: Utility reads longs from standard input and converts them to a new radix (base)\n"
               "Usage: convert [-b BASE] [-r START FINISH]\n"
               "1 < BASE < 37\n"
               "START and FINISH are long integers\n"
               "Options:\n"
               "-b BASE Specify the base for conversion (default: 16)\n"
               "-r START FINISH Specify a range of numbers to convert\n"
               "Side Note: For bases higher than 10, capital letters A through Z should represent digit values 11 through 36.\n"
               "--help Show detailed help about the program usage.\n");
        return 0;
    }

    else if (argc < 2) {
        return 0; // Check for arguments, if none, use default values
    }

    else if (argc > 6) { //if more than 5 arguments, automatically return erorr
        fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) { // validate input(less redudant,more efficient process than commit 5)
        if (((strcmp(argv[i], "-b") == 0) && (i==1))) { //if first argument -b
            if (i+1 >= argc || !is_valid_integer(argv[i+1])) {  //if less than 2 arguments or second argument not valid, show error
                fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                return 1;
            }
            *base = atoi(argv[i+1]); //change to int
            if (*base < MIN_BASE || *base > MAX_BASE) { //if not in acceptable base range, show error
                fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                return 1;
            }
        } 
	else if ((strcmp(argv[i], "-r") == 0) && (i==1 || i==3))  { //checks if first or third argument is -r
            if (i + 2 >= argc || !is_valid_integer(argv[i + 1]) || !is_valid_integer(argv[i + 2])) {  // checks if less than 3 arguments or not valid range numbers and displays error if necessary
                fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                return 1;
            }
            *start = atol(argv[++i]); //change to int
            *finish = atol(argv[++i]);
        } 
	else if (i==1 || i==3) { //if first or third argument not correct, then display error
            fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
            return 1;
        }
    }

    return 0; //if success,  return 0
}

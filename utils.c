#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_BASE 2
#define MAX_BASE 36

// Function to parse command-line arguments
int parse_args(int argc, char *argv[], int *base, long *start, long *finish) {
    *base = 16; // Default base is 16
    *start = 0;
    *finish = 0;

    if (argc < 2) return 0;  // Checks for arguments, if none, use default values 

    // Check for base entered
    if (strcmp(argv[1], "-b") == 0 && argc > 2) {
        *base = atoi(argv[2]);  // Convert the base from string to int
        if (*base < MIN_BASE || *base > MAX_BASE) {
            fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers");
            return -1; //show error
        }
        argv += 2;  // Skips
    }

    // Check for range entered
    if (argc > 4 && strcmp(argv[1], "-r") == 0) {
        *start = atol(argv[2]);   // Convert start to long type
        *finish = atol(argv[3]);  // Convert finish to long type
    }

    return 0;  // Return 0 to indicate success
}

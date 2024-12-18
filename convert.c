#include <stdio.h>
#include "convert.h"

// Function that converts number to base recursively
void convert(long number, int base) {
    if (number == 0) {
        return;  //Stops when number reaches 0
    }

    //continue for next digit
    convert(number / base, base);

    int digit = number % base; //Assigns current digit
    if (digit < 10) {  //Checks if digit is less than 10 and assigns 0-9 value respectively
        putchar('0' + digit);
    } 
    else { //Otherwise assigns letter value if digit > 10
        putchar('A' + (digit - 10));
    }
}

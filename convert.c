/* Author: Pavan Patel
 * Program Info: Convert function that converts the inputted number to its equivalent for inputted base
 **/
#include <stdio.h>
#include "convert.h"

// Function that converts number to base recursively, input is long number and int base, while return is void
void convert(long number, int base) {
    if (number == 0) {
        return;  //Stops when number reaches 0
    }	
    if (number < 0) {
        putchar('-'); // Print the negative sign
        number = -number; // Converts to positive
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

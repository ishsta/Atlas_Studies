#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////
//  Filename:    pos_neg_zero.c
//  Description: demonstrate three methods using if, if-else and else-if to
//               determine if an input integer is positive, negative, or zero.
//////////////////////////////////////////////////////////////////////////////


int main(){

    int number = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    //////////////////////////////////////////////////////////////////////////////
    //  Method 1: if only
    //////////////////////////////////////////////////////////////////////////////

    if (number > 0) {
        printf("M1: [%d] is positive. \n", number);
    }

    if (number < 0) {
        printf("M1: [%d] is negative. \n", number);
    }

    if (number == 0) {
        printf("M1: [%d] is zero. \n", number);
    }

    //////////////////////////////////////////////////////////////////////////////
    // Method 2: if-else only
    //////////////////////////////////////////////////////////////////////////////

    if (number <= 0) {
        if (number == 0)
            printf("M2: [%d] is zero. \n", number);
        else
            printf("M2: [%d] is negative. \n", number);
    } else {
        printf("M2: [%d] is positive. \n", number);
    }

    //////////////////////////////////////////////////////////////////////////////
    // Method 3: else-if
    //////////////////////////////////////////////////////////////////////////////

    if (number > 0) {
        printf("M3: [%d] is positive. \n", number);
    } else if (number < 0) {
        printf("M3: [%d] is negative. \n", number);
    } else if (number == 0) {
        printf("M3: [%d] is zero. \n", number);
    }

    return 0;

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*########################################################################
Filename: rng.c
Description:  
1. accept user input to select the lower limit (minimum number), the
upper limit (maximum number) and the number of randon numbers desired.
2. print the random numbers to the console.
Note: introduce rand(), srand() and time() functions.
#########################################################################*/

int main(void) {
    int lower, upper, count = 0;
    srand(time(NULL)); // Initialize the random seed based on the current time

    printf("Enter the lower limit: ");
    scanf("%d", &lower);

    printf("Enter the upper limit: ");
    scanf("%d", &upper);

    printf("Enter the count of random numbers to generate: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower; // generates number between upper-lower, inclusive.
        printf("Random number: %d\n", num);
    }

    return 0;
}
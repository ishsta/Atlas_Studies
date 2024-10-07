#include  <stdio.h>
#include  <string.h>
#include <time.h>


/*
 * switch.c - Introductory examples of switch/case statement in C
 *
 * To compile the example, run this command...
 *      gcc -o switch switch.c
 *
 * To run the executable (after compiling)...
 *      ./switch
 *
*/

/*
 * Switch/case statement 
 * Similar to  conditional if/else but optimized to match specific (constant) values
 *
 * USAGE:
 *
 * switch (<variable_or_expression>) {
 * case <constant_value>:
 *      // code for this case here
 *      break;
 *
 *  /// Additional cases...
 *
 * default:
 *      // code for default case (no cases matched)
 *      break;
 * }
 *
 *
*/

int main(void) {
    int value;

    srand(time(NULL));
    printf("Rolling dice...\n"); 

    value = rand() % 6 + 1; /* random value from 1-6 */

    switch(value) {
        case 1: /* if (value == 1) */
            printf("You rolled a 1!\n");
            break;
        case 2: /* if (value == 2) */
            printf("You rolled a 2!\n");
            break;
        case 3: /* if (value == 3) */
            printf("You rolled a 3!\n");
            break;
        case 4: /* if (value == 4) */
            printf("You rolled a 4!\n");
            break;
        case 5: /* if (value == 5) */
            printf("You rolled a 5!\n");
            break;
        case 6: /* if (value == 6) */
            printf("You rolled a 6!\n");
            break;
        default: /* else */
            printf("Invalid roll!\n");
            break;
    }

    return 0;
}
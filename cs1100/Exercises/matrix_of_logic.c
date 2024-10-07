#include <stdio.h>
#include <time.h>

#define VALID 1
#define NOT_VALID 0

int main(void) {
    char userInput;
    int p, q, result;
    srand(time(NULL));
    int isValid = NOT_VALID;
    
    // Display welcome message

    printf("Welcome to the Matrix of Logic!\n");

    // assign either a 0 or 1 to p and q

    p = rand() % 2;
    q = rand() % 2;

    // print the choices of r, b, w, k, to the user until q or Q are chosen.
    do {

        printf("You have a choice to make:\n");
        printf("Take the red pill (r), blue pill (b), white pill (w), or black pill (k): ");
        printf("Binary dice roll: p = %d, q = %d\n", p, q);
        scanf("\n%c", &userInput);

         switch(userInput) {
             case 'r':
                 result = (p && q) ? 1 : 0;
                 printf("You took the red pill. Demonstrating LOGICAL AND: %d && %d = %d\n", p, q, result);
                 break;
             case 'b':
                 result = (p ^ q) ? 1 : 0;
                 printf("You took the blue pill. Demonstrating LOGICAL XOR: %d ^ %d = %d\n", p, q, result);
                 break;
             case 'w':
                 result = (p || q) ? 1 : 0;
                 printf("You took the white pill. Demonstrating LOGICAL OR: %d || %d = %d\n", p, q, result);
                 break;
             case 'k':
                 result = (p != q) ? 1 : 0; 
                 printf("You took the black pill. Demonstrating LOGICAL NOT: !%d = %d and !%d = %d\n", p, !p, q, !q);
                 break;
             case 'q':
                 printf("Quitting!\n");
                 isValid = VALID;
                 break;
             case 'Q':
                 printf("Quitting!\n");
                 isValid = VALID;
                 break;
             default :
                 printf("Invalid choice. You must choose the red, blue, white, or black pill.\n");
         }
    } while(!isValid);


    return 0;
}
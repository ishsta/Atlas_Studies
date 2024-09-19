#include <stdio.h>
#include <time.h>

int main(void) {
    char userInput;
    int p, q, result;
    srand(time(NULL));
    
    // Display welcome message
    printf("Welcome to the Matrix of Logic!\n");
    printf("You have a choice to make: \n");

    p = rand() % 2;
    q = rand() % 2;
    // prompt user to make choice r, b, w, k, based on pill color
    // validate user input
    // take user answer and store it.
    do {
        printf("\nTake the red pill (r), blue pill (b), white pill (w), or black pill (k):");
        scanf("%c", &userInput);

        switch(userInput) {
            case 'r':
                result = (p && q) ? 1 : 0;
                printf("Binary dice roll: p = %d, q = %d\n", p, q);
                printf("You took the red pill. Demonstrating LOGICAL AND: %d && %d = %d \n", p, q, result);
                break;
            case 'b':
                result = (p ^ q) ? 1 : 0;
                printf("Binary dice roll: p = %d, q = %d\n", p, q);
                printf("You took the blue pill. Demonstrating LOGICAL XOR: %d ^ %d = %d \n", p, q, result);
                break;
            case 'w':
                result = (p || q) ? 1 : 0;
                printf("Binary dice roll: p = %d, q = %d\n", p, q);
                printf("You took the white pill. Demonstrating LOGICAL OR: %d || %d = %d \n", p, q, result);
                break;
            case 'k':
                result = (p != q) ? 1 : 0;
                printf("Binary dice roll: p = %d, q = %d\n", p, q);
                printf("You took the black pill. Demonstrating LOGICAL NOT: !%d = %d and !%d = %d \n", p, !p, q, !q);
                break;
            case 'q':
                printf("Quitting!");
                break;
        }
    } while(userInput != 'q' || userInput != 'r' || userInput != 'b' || userInput != 'w' || userInput != 'k');

    return 0;
}
#include <stdio.h>

#define OFF 0
#define ON 1

int main(void) {
    int power = ON;
    int option1;
    int option2;
    int option3;
    float result;

    // print welcome message
    printf("Calculator is ON\n");

    // display menu until user chooses 0
    do {

        printf("\nCalculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("0. Turn OFF\n");
        printf("Enter your selection: ");
        scanf("%d", &option1);

        switch (option1)
        {
        case 0:
            power = OFF;
            printf("Calculator is OFF\n");
            break;
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &option2, &option3);
            result = option2 + option3;
            printf("Result: %.2f\n", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &option2, &option3);
            result = option2 - option3;
            printf("Result: %.2f\n", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &option2, &option3);
            result = option2 * option3;
            printf("Result: %.2f\n", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &option2, &option3);
            
            // check if the second number entered is 0
            // if true, dispay error
            // else, display result
            if (option3 == 0) {
                printf("Error: Division by zero!\n");
                break;
            } else {
                result = (float)option2 / option3;
                printf("Result: %.2f\n", result);
                break;
            }

            // If an invalid selection is made, continues showing the menu.
        default:
            printf("Invalid selection. Please try again.\n");
            continue;
        }

    } while (power);

    return 0;
}
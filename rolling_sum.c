#include <stdio.h>
#include <ctype.h> // for isdigit()

#define VALID_INPUT 1
#define INVALID_INPUT 0

int main(void) {

    int sum = 0;
    char input [100];
    int num, valid_input;

    printf("Enter integers one by one (enter 'q' to quit): \n");

    while (1) {
        printf("Enter an integer: ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q' || input[0]== 'Q') {
            printf("Quitting...\n");
            return 0;
        }

        valid_input = VALID_INPUT;
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == '\n') {
                input[i] = '\0';
                break;
            }
            if (!isdigit(input[i]) && input[i] != '-') {
                valid_input = INVALID_INPUT;
                break;
            }
        }
        if (valid_input) {
            sscanf(input, "%d", &num);
            sum += num;
            printf("Current sum: %d\n", sum);
        }  else {
            printf("Invalid input. Please enter a valid integer.\n");
        }
    }

    return 0;
}
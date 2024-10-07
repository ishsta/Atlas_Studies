#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LOCKERS 100
#define MAX_ITEM_LENGTH 50

int is_valid_number(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0; // If a non-digit character is found, it's not a valid number
        }
    }
    return 1; // All characters are digits
}

int main(void){
    int choice;
    int locker;
    char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH];
    char item[MAX_ITEM_LENGTH];
    int rows = sizeof(lockers)/sizeof(lockers[0]);
    int columns = sizeof(lockers[0])/sizeof(lockers[0][0]);
    char input[10];

    for (int i = 0; i < MAX_LOCKERS; i++) {
        strcpy(lockers[i], "empty");
    }

    do {
        printf("\nLocker Rental Menu\n");
        printf("=============================\n");
        printf("1. View a locker\n");
        printf("2. Rent a locker\n");
        printf("3. End a locker rental\n");
        printf("4. List all locker contents\n");
        printf("5. Quit\n");

        printf("Enter your menu_choice (1-5): ");
        scanf("%s", input);

        if (!is_valid_number(input)) {
            printf("Invalid input. Please enter a valid menu choice.\n");
            printf("Invalid menu_choice. Please try again.\n");
            continue;
        }

        choice = atoi(input);  // Convert the input string to an integer

        switch (choice)
        {
        case 1:
            printf("Enter locker number (1-100): ");
            scanf("%d", &locker);

            if (locker < 1 || locker > 100) {
                printf("Sorry, there are only 100 lockers available.\n");
            } else {
                if (strcmp(lockers[locker - 1], "empty") == 0) {
                    printf("Locker %d is EMPTY.\n", locker);
                } else {
                    printf("Locker %d contents: %s\n", locker, lockers[locker - 1]);
                }
            }
            break;
        case 2:
            printf("Enter locker number (1-100): ");
            scanf("%d", &locker);

            if (locker < 1 || locker > 100) {
                printf("Sorry, there are only 100 lockers available.\n");
            } else {
                if (strcmp(lockers[locker - 1], "empty") == 0) {
                    printf("Enter the item you want to store in the locker: ");
                    scanf("%s", lockers[locker - 1]);

                    printf("Locker %d has been rented for %s storage.\n", locker, lockers[locker - 1]);
                } else {
                    printf("Sorry, but locker %d has already been rented!\n", locker);
                }
            }
            break;
        case 3:
            printf("Enter locker number (1-100): ");
            scanf("%d", &locker);

            if (locker < 1 || locker > 100) {
                printf("Sorry, there are only 100 lockers available.\n");
            } else {
            if (strcmp(lockers[locker - 1], "empty") == 0) {
                printf("Locker %d is not currently rented.\n", locker);
            } else {
                printf("Locker %d rental has ended, please take your %s.\n", locker, lockers[locker - 1]);
                strcpy(lockers[locker - 1], "empty");  // Reset the locker to "empty"
                }
            }
            break;
        case 4:
            {
                int any_rented = 0;  // Flag to track if any lockers are rented
                for (int i = 0; i < MAX_LOCKERS; i++) {
                    if (strcmp(lockers[i], "empty") != 0) {
                        printf("Locker %d: %s\n", i + 1, lockers[i]);
                        any_rented = 1;  // Set flag when at least one locker is rented
                    }
                }
                if (!any_rented) {
                    printf("No lockers are currently rented.\n");
                }
            }
            break;
        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid menu_choice. Please try again.\n");
            continue;
        }

    }while (choice != 5);

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_LOCKERS 100
#define MAX_ITEM_LENGTH 50

int main(void){
    int choice;
    int locker;
    char lockers[MAX_LOCKERS][MAX_ITEM_LENGTH];
    char item[MAX_ITEM_LENGTH];

    for (int i = 0; i < MAX_LOCKERS; i++) {
        strcpy(lockers[i], "empty");
    }

    do {
        printf("Locker Rental Menu\n");
        printf("=============================\n");
        printf("1. View a locker\n");
        printf("2. Rent a locker\n");
        printf("3. End a locker rental\n");
        printf("4. List all locker contents\n");
        printf("5. Quit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter locker number (1-100): ");
            scanf("%d", &locker);

            if (locker < 1 || locker > 100) {
                printf("Sorry, there are only 100 lockers available.\n");
            } else {
                if (strcmp(lockers[locker - 1], "empty") == 0) {
                    printf("Locker %d is empty.\n", locker);
                } else {
                    printf("Locker %d contains: %s\n", locker, lockers[locker - 1]);
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

                    printf("Locker %d has been rented out for %s storage.\n", locker, lockers[locker - 1]);
                } else {
                    printf("Sorry, but locker %d has already been rented!\n", locker);
                }
            }
            break;
        case 3:
            break;
        case 4:
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
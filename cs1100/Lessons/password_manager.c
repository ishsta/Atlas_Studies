/*
 * Password Manager
 *
 * This program provides a menu-based interface for password management. Users can
 * choose to either enter their password or change the password. When entering the
 * password, the program demonstrates the usage of different buffering modes
 * (_IOFBF, _IOLBF, _IONBF) with setvbuf(). If the user fails to enter the correct
 * password three times, the program quits. When changing the password, the program
 * asks for the current password and verifies it against the locally stored password.
 * If the current password is correct, the user is prompted to enter a new password.
 * However, the password change is not allowed, and the program displays a message
 * saying "Change is not allowed on a full moon" before quitting.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20
#define BUFFER_SIZE 100
#define MAX_ATTEMPTS 3
#define STORED_PASSWORD "secretpass"

bool enterPassword(void) {
    char buffer[BUFFER_SIZE];
    char password[MAX_PASSWORD_LENGTH];
    int attempts =  0;

    while (attempts < MAX_ATTEMPTS) {
        // Fully buffered output
        setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
        printf("Enter the password: ");
        fflush(stdout); // Flush the output buffer
        scanf("%s", password);
        fflush(stdin); // Flush the input buffer

        if (strcmp(password, STORED_PASSWORD) == 0)  {
            printf("Password is correct. Access granted.\n");
            fflush(stdout); // Flush the output buffer
            return true;
        } else {
            printf("Password is incorrect. Access denied.\n");
            fflush(stdout); // Flush the output buffer
            attempts++;
        }
    }

    // Flush any remaining output before printing the final message
    fflush(stdout);
    setvbuf(stdout, NULL, _IONBF, 0); // Set unbuffered output mode
    printf("Maximum attempts reached. Quitting.\n");
    return false;
}

void changePassword(void) {
    char currentPassword[MAX_PASSWORD_LENGTH];

    // Line buffered output
    setvbuf(stdout, NULL, _IOLBF, 0);
    printf("Enter the current password:  ");
    fflush(stdout); // Flush the output buffer
    scanf("%s", currentPassword);
    fflush(stdin); // Flush the input buffer

    if (strcmp(currentPassword, STORED_PASSWORD) != 0) {
        printf("Invalid current password. Password change denied.\n");
        return;
    }

    //  Unbuffered output
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Enter a new password: ");
    fflush(stdout); // Flush the output buffer
    scanf("%s", currentPassword); // Reuse currentPassword variable
    fflush(stdin); // Flush the input buffer

    printf("Change is only allowed on a full moon. Quitting.\n");

}

int main(void) {
    int choice;
    setvbuf(stdout, NULL, _IONBF, 0); // Set unbuffered output mode
    printf("Password Manager\n");
    printf("1. Enter Password\n");
    printf("2. Change Password\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    fflush(stdin); // Flush the input buffer

    switch (choice) {
        case 1:
            enterPassword();
            break;
        case 2:
            changePassword();
            break;
        default:
            printf("Invalid choice. Quitting.\n");
    }

    return 0;
}
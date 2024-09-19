#include <stdio.h>
#include <string.h>

/*
 * File: enhanced_password_guesser.c
 * Author: [Your Name]
 * Date: [Current Date]
 * Description: This program simulates a password-based access control system.
 *              It prompts the user to enter a password and grants access if 
 *              the password matches either the stored password or an 
 *              alternate password. If access is granted, it simulates an OS 
 *              startup sequence. The program allows up to 3 invalid password 
 *              attempts before quitting.
 */

#define MAX_PASSWORD_LENGTH 20
#define MAX_ATTEMPTS 3

int main(void) {
    char userPassword[MAX_PASSWORD_LENGTH];
    char *storedPassword = "password123";
    char *alternatePassword = "alternate789";
    char *message;
    int attempts_cnt = 0;
    int isValid = 0;

    // Input: Prompt the user to enter a password
    do {
        printf("Enter the password: ");
        scanf("%s", userPassword);

        // Processing: Check if the enterd password matches either
        isValid = (strcmp(userPassword, storedPassword) == 0 || strcmp(userPassword, alternatePassword) == 0) ? 1 : 0;

        if (!isValid) {
            attempts_cnt++;
            printf("Invalid password. Attempt %d of %d. \n", attempts_cnt, MAX_ATTEMPTS);
        }
    } while (!isValid && attempts_cnt < MAX_ATTEMPTS);

    // Output: Simulate OS startup sequence if access is granted
    if (isValid) {
        printf("OS startup sequence initiated.\n");
        printf("Loading system components...\n");
        printf("System ready.\n");
    }

    return 0;
}
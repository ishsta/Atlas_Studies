#include <stdio.h>
#include <string.h>

    /*
    * File: password_guesser.c
    * Author: [Your Name]
    * Date: [Current Date]
     * Description: This program validates a password-based access control system.
     *              It prompts the user to enter a password and grants access if 
     *              the password matches either the stored password or an 
     *              alternate password. If access is granted, it simulates an OS 
     *              startup sequence.
    */

#define MAX_PASSWORD_LENGTH 20

int main(void) {
    char userPassword[MAX_PASSWORD_LENGTH];
    char *storedPassword = "password123";
    char *alternatePassword = "alternate123";
    char *message;

    // Input: prompt the user to enter a passwod
    printf("Enter the password: ");
    scanf("%s", userPassword);

    // Processsing: Check if the entered password matches either the stored password or the alternate password
    int isValid = (strcmp(userPassword, storedPassword) == 0 || strcmp(userPassword, alternatePassword) == 0) ? 1 : 0;

    // Output: Display a message based on the password validity
    message = isValid ? "Access granted. Starting OS..." : "Invalid password. Exiting...";
    printf("%s\n", message);

    if (isValid) {
        printf("OS startup sequence initiated.\n");
        printf("Loading system components...\n");
        printf("System ready\n");
    }

    return 0;
}
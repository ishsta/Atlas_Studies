#include <stdio.h>
#include <string.h>

/*
 * Multi-Language Greeter
 *
 * This program greets the user in their preferred language by displaying
 * the "Hello, World!" message in English, Spanish, French, or German.
 * The user is prompted to enter their name and choose a language.
 * The program validates the user's language input and displays the
 * corresponding greeting.
 */

#define LANG_NOT_VALID 0 // for flag, language is not valid or false or 0
#define LANG_IS_VALID 1 // for flag, language is valid or true or 1

int main(void) {
    char greetings[][20] = {"Hello, world!", "Hola, mundo!", "Bonjour, monde!", "Hallo, Welt!"};
    char languages[][10] = {"English", "Spanish", "French", "German"};
    char input_name[20];
    char input_language[20];
    int validLanguage = LANG_NOT_VALID; // flag variable for whether  string is valid

    printf("Enter your name: ");
    scanf("%s", input_name);

    char greeting[30] = "Hello, ";
    strcat(greeting, input_name);
    strcat(greeting, "!");

    // check the language string input by the user and wait for a valid input language
    while (LANG_NOT_VALID == validLanguage) {
        printf("\nEnter a language (English, Spanish, French, German): ");
        scanf("%s", input_language);

        for (int i = 0; i < 4; i++) {
            if (strcmp(input_language, languages[i]) == 0) {
                printf("In %s, \"Hello, World!\" is \"%s\"\n", languages[i], greetings[i]);
                validLanguage =  LANG_IS_VALID;
            }
        }

        if (LANG_NOT_VALID == validLanguage) {
            printf("Invalid language. Please try again.\n");
        }
    }
    return 0;
}
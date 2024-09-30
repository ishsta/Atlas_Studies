#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char*);
int lengthOfString(char*);
int countOccurence(char*, char);
void reverseArray(char*, int);

#define MAX_INPUT_STRING_SIZE 100
#define PALINDROME_FOUND 1
#define PALINDROME_NOT_FOUND 0

int main(int argc, char *argv[]) {
    char userInput[10];
    int input;

    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    do {
        printf("\nString Processing Tool\n");
        printf("1. Count characters\n");
        printf("2. Reverse string\n");
        printf("3. Convert to uppercase\n");
        printf("4. Check palindrome\n");
        printf("5. Count occurrences of a character\n");
        printf("6. Exit\n");

        printf("Enter your input_selection: ");
        fgets(userInput, sizeof(userInput), stdin);

        input = atoi(userInput);

        switch (input)
        {
        case 1:
            printf("Number of characters: %d\n", lengthOfString(argv[1]));
            printf("Press Enter to continue...");
            getchar();
            break;
        case 2:{
            int size = strlen(argv[1]);
            reverseArray(argv[1], size);
            printf("Reversed string: %s\n", argv[1]);
            printf("Press Enter to continue...");
            getchar();
            break;
        }
        case 3:{
            char* string_ptr = argv[1];
            for (int i = 0; string_ptr[i]; i++) {
                string_ptr[i] = toupper(string_ptr[i]);
            }
            printf("Uppercase string: %s\n", string_ptr);
            printf("Press Enter to continue...");
            getchar();
            break;
        }
        case 4:{
            char* input_string_ptr = argv[1];
            if (isPalindrome(input_string_ptr) == PALINDROME_FOUND) {
                printf("%s is a palindrome\n", input_string_ptr);
            }   else {
                printf("%s is not a palindrome\n", input_string_ptr);
            }
            printf("Press Enter to continue...");
            getchar();
            break;
        }
        case 5:{
            char countCharacter;
            printf("Enter a character to count: ");
            scanf("%c", &countCharacter);
            printf("Occurrences of '%c': %d\n", countCharacter, countOccurence(argv[1], countCharacter));
            printf("Press Enter to continue...");
            while (getchar() != '\n');
            getchar();
            break;
        }
        case 6:
            printf("Exiting the program.\n");
            break;
        }

    }while(input != 6);

}

int isPalindrome(char* string_ptr) {
    char* start_ptr = string_ptr;
    char* end_ptr = string_ptr + strlen(string_ptr) - 1;

    // Compare characters pointed by 'start_ptr' and 'end_ptr'
    while (start_ptr < end_ptr) {
        if (tolower(*start_ptr) != tolower(*end_ptr)) {
            return PALINDROME_NOT_FOUND;
        }
        start_ptr++;
        end_ptr--;
    }
    return PALINDROME_FOUND;
}

int lengthOfString(char* string_ptr) {
    int length = strlen(string_ptr);
    return length;
}

int countOccurence(char* string_ptr, char search_char) {
    int i = 0, count = 0;

    while(string_ptr[i] != '\0') {

        if(string_ptr[i] == search_char) {
            count++;
        }

        i++;
    }

    return count;

}

void reverseArray(char* string_ptr, int size) {
    char *start = string_ptr;
    char *end = string_ptr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
#include <stdio.h>
#include <ctype.h>  // For tolower()
#include <string.h> // For strlen()

int isPalindrome(char*); // Function prototype (?)

#define PALINDROME_FOUND 1
#define PALINDROME_NOT_FOUND 0

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char* input_string_ptr = argv[1];

    if (isPalindrome(input_string_ptr) == PALINDROME_FOUND) {
        printf("String is a palindrome.\n");
    }   else {
        printf("String is not a palindrome.\n");
    }

    return 0;
}

// Function to check if a string is a palindrome
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
#include <stdio.h>
#include <string.h>
#include <ctype.h> // need for tolower()

/*
 * File: animal_category_id.c
 * Author: [Your Name]
 * Date: [Current Date]
 *
 * Description:
 * This program allows the user to enter an animal name and determines whether
 * the animal is a canine, feline, or rodent. It uses arrays to store the names
 * of animals in each category and compares the user input with the stored names
 * to classify the animal. The program continues to prompt the user for animal
 * names until the user enters 'exit' to quit the program.
 */

#define ANIMAL_FOUND 1
#define ANIMAL_NOT_FOUND 0

int main() {
    // Define arrays of animal names for each category
    char *canines[] = {"dog", "wolf", "fox", "coyote"};
    char *felines[] = {"cat", "lion", "tiger", "leopard"};
    char *rodents[] = {"mouse", "rat", "squirrel", "hamster"};

    // Calculate the number of elements in each array using sizeof operator
    int numCanines = sizeof(canines) / sizeof(canines[0]);
    int numFelines = sizeof(felines) / sizeof(felines[0]);
    int numRodents = sizeof(rodents) / sizeof(rodents[0]);

    // Declare a character array to store the user input
    char animalName[20];

    // Start a do...while loop to repeatedly prompt the user for input
    do {
        // prompt the user to enter an animal name or 'exit' to quit
        printf("\nEnter an animal name (or 'exit' to quit): ");
        scanf("%s", animalName);

        for (int i = 0; animalName[i]; i++) {
            animalName[i] = tolower(animalName[i]);
        }

        // Check if the user entered 'exit' to quit the program
        if (strcmp(animalName, "exit") == 0) {
            break;
        }

        // Initialize a flag to track if the animal is found in any category
        int found = ANIMAL_NOT_FOUND;

        // Check if the animal is a canine
        for (int i = 0; i < numCanines; i++) {
            if (strcmp(animalName, canines[i]) == 0) {
                printf("%s is a canine.\n", animalName);
                found = ANIMAL_FOUND;
                break;
            }
        }

        // Check if the animal is a feline if not found in canines
        if (found == ANIMAL_NOT_FOUND) {
            for (int i = 0; i < numFelines; i++) {
                if (strcmp(animalName, felines[i]) == 0) {
                    printf("%s is a feline.\n", animalName);
                    found = ANIMAL_FOUND;
                    break;
                }
            }
        }

        // Check if the animal is a rodent if not found in canines or felines
        if (found == ANIMAL_NOT_FOUND) {
            for (int i = 0; i < numRodents; i++) {
                if (strcmp(animalName, rodents[i]) == 0) {
                    printf("%s is a rodent.\n", animalName);
                    found = ANIMAL_FOUND;
                    break;
                }
            }
        }

        // If the animal is not found in any category, print a message
        if (found == ANIMAL_NOT_FOUND) {
            printf("%s is not a canine, feline, or rodent.\n", animalName);
        }
    } while (1);

    // Print a message when the user chooses to exit the program
    printf("Exiting the program.\n");
    
    return 0;
}
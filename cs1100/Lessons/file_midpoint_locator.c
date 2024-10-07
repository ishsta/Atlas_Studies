/*
 * file_midpoint_locator.c
 *
 * This program demonstrates how to find the middle line of a text file.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

/*
 * Function: find_text_file_midpoint
 * Description: Finds and prints the middle line of a text file.
 * Parameters:
 *   - filename: The name of the file to read.
 */
void find_text_file_midpoint(const char *filename) {
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the text file. \n");
        return;
    }

    // Find the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file); // Reset file pointer to beginning

    // Calculate the middle position
    long middle_position = file_size / 2;

    // Seek to the middle position
    fseek(file, middle_position, SEEK_SET);

    // Move back to the start of the current line
    while (middle_position > 0 && fgetc(file) != '\n') {
        middle_position--;
        fseek(file, middle_position, SEEK_SET);
    }

    // If we're not at the start of the file, move to the next line
    if (middle_position != 0) {
        fgetc(file); // Move past the newline character
    }

    // Read the middle line
    char buffer[MAX_LINE_LENGTH];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("Middle line of text file: %s\n", buffer);
    } else {
        printf("Failed to read the middle line.\n");
    }

    // Close the file
    fclose(file);
}

int main(void) {
    char text_filename[] = "input_numbered_lines.txt";
    find_text_file_midpoint(text_filename);
    return 0;
}
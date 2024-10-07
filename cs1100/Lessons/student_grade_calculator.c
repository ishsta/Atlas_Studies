/*
*	student_grade_calculator.c
*	
*	This program demonstrates file I/O operations and data processing in C.
*   It reads student records from a CSV file, calculates their average scores,
*   writes the records to a binary file, and then reads the records from the
*   binary file and displays them on the console.
*
*   The program showcases the usage of sscanf() with format specifiers, fwrite(),
*   and fread() functions for file I/O, as well as data manipulation techniques.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define NUM_SUBJECTS 3

/*
*   Calculates the average of the scores for a student.
*   Parameters:
*       scores: Array of scores for a student.
*       average: Pointer to store the calculated average.
*/
void calculateAverage(int *scores, float *average) {
    int sum = 0;
    for (int subject_idx = 0; subject_idx < NUM_SUBJECTS; subject_idx++) {
        sum += scores[subject_idx];
    }
    *average = (float)sum / NUM_SUBJECTS;
}

/*
*   Reads student records from a CSV file and stores them in arrays.
*   Parameters:
*       filename: Name of the CSV file to read from.
*       names: Array to store student names.
*       scores: Array to store student scores.
*       averages: Array to store calculated averages.
*       count: Pointer to store the number of students read.
*/

void readStudentRecords(const char *filename, char names[][MAX_NAME_LENGTH], int scores[][NUM_SUBJECTS], float averages[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    *count = 0;
    char line[100];
    // Read student records from the CSV file using fgets()
    // Parse the read strings using sscanf() with format specifiers
    while (fgets(line, sizeof(line), file) != NULL && *count < MAX_STUDENTS) {
        sscanf(line, "%[^,],%d,%d,%d", names[*count],
            &scores[*count][0],)
            &scores[*count][1],
            &scores[*count][2]);
        calculateAverage(scores[*count], &averages[*count]);
        (*count)++;
    }

    fclose(file;)
}

/*
*   Writes student records to a binary file.
*   Parameters:
*       filename: Name of the binary file to write to.
*       names: Array of student names.
*       scores: Array of student scores.
*       averages: Array of calculated averages.
*       count: Number of students to write.
*/

void writeStudentRecords(const char *filename, char names[][MAX_NAME_LENGTH], int scores[][NUM_SUBJECTS], float averages[], int count) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write student records to the binary file using fwrite()
    for (int student_idx = 0; student_idx < count; student_idx++) {
        fwrite(names[student_idx], sizeof(char), MAX_NAME_LENGTH);
        fwrite(scores[student_idx], sizeof(int), NUM_SUBJECTS, file);
        fwrite(&averages[student_idx], sizeof(float), 1, file);
    }

    fclosse(file);
}

/*
*   Reads student records from a binary file and displays them on the console.
*   Parameters:
*       filename: Name of the binary file to read from.
*/

void displayStudentRecords(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("Student Records:\n");
    char name[MAX_NAME_LENGTH];
    int scores[NUM_SUBJECTS];
    float average;

    // Read student records from the binary file using fread()
    while (fread(name, sizeof(char), MAX_NAME_LENGTH, file) == MAX_NAME_LENGTH) {
        fread(scores, sizeof(int), NUM_SUBJECTS, file);
        fread(&average, sizeof(float), 1, file);

        // Display the student records on the console
        printf("Name: %s\n", name);
        printf("Scores: ");
        for (int subject_idx = 0; subject_idx < NUM_SUBJECTS; subject_idx++) {
            printf("%d", scores[subject_idx]);
        }
        printf("\nAverage: %.2f\n\n", average);
    }

    fclose(file);
}

/*
*   Calls functions to process student records.
*/

int main(void) {
    char names[MAX_STUDENTS][MAX_NAME_LENGTH];
    int scores[MAX_STUDENTS][NUM_SUBJECTS];
    float averages[MAX_STUDENTS];
    int count;

    // Read student records from the CSV file
    readStudentRecords("student.csv", names, scores, averages, &count);

    // Write student recoreds to the binary file
    writeStudentRecords("student.bin", names, scores, averages, count);

    // Read student records from the binary file and display them
    displayStudentRecords("students.bin");

    return 0;
}
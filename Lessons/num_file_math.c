/* 
* Numerical File Math Program *  
* This program reads integers from an input file, calculates their sum, 
* and writes the result to an output file. It demonstrates the usage of 
* file I/O functions (fopen, fclose, fscanf, fprintf), basic array  
* manipulation, and error handling using the exit() function. 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

/* 
* Function: readNumbersFromFile 
* Description: Reads integers from a file and stores them in an array. 
* Parameters: 
*   - filename: Name of the input file 
*   - numbers: Array to store the read numbers 
*   - count: Pointer to store the count of numbers read 
* Returns: 1 if successful, exits program if file can't be opened 
*/

int readNumbersFromFile(const char* filename, int numbers[], int* count) {  

    // Open the file for reading    
    FILE* file = fopen(filename, "r");    

    if (file == NULL) {        
        printf("Error opening input file.\n");        
        exit(1);  // Exit the program if file can't be opened    
        }

        *count = 0;    

        // Read numbers from file until EOF or MAX_NUMBERS is reached    
    while (fscanf(file, "%d", &numbers[*count]) == 1 && *count < MAX_NUMBERS) {        
        (*count)++;    
        } 

    fclose(file);  // Close the file    
    return 1;
    }

/* 
* Function: calculateSum 
* Description: Calculates the sum of numbers in an array. 
* Parameters: 
*   - numbers: Array of integers 
*   - count: Number of elements in the array 
* Returns: Sum of all numbers in the array 
* 
*/

int calculateSum(int numbers[], int count) {    
    int sum = 0;    
    // Iterate through the array and add each number to sum    
    for (int numbers_idx = 0; numbers_idx < count; numbers_idx++) {        
        sum += numbers[numbers_idx];    
        }    
        return sum;
    }

/* 
* Function: writeResultToFile 
* Description: Writes the calculated sum to an output file. 
* Parameters: 
*   - filename: Name of the output file 
*   - sum: The sum to be written to the file 
* */

void writeResultToFile(const char* filename, int sum) {  

    // Open the file for writing    
    FILE* file = fopen(filename, "w"); 

     if (file == NULL) {        
        printf("Error opening output file.\n");        
        exit(1);  // Exit the program if file can't be opened   
        
        }    
        
        // Write the sum to the file    
        fprintf(file, "Sum: %d\n", sum);    
        fclose(file);  // Close the file
    }
                     
int main(void) {    
    int numbers[MAX_NUMBERS];    
    int count = 0;    
    
    // Read numbers from input file    
    if (readNumbersFromFile("input.txt", numbers, &count)) { 

        // Calculate the sum of the numbers        
        int sum = calculateSum(numbers, count); 

        // Write the sum to the output file        
        writeResultToFile("output.txt", sum);        
        printf("Sum calculated and written to output.txt\n");    
        }    

        return 0;
    }
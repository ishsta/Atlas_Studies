#include <stdio.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////////
// File: geometric_area_calculator.c
// Description: This program calculates the areas of various geometric shapes 
//              based on user input. It provides a menu-driven interface for 
//              selecting the shape and entering the required dimensions.
//              The program demonstrates different methods for calculating 
//              the areas, including direct calculation, using functions, 
//              macros, and the math.h library.
// Author: [Ishsta Glass]
// Date: [9/20/24]
//////////////////////////////////////////////////////////////////////////////

#define SQUARE_NUM(x) (x * x)
#define PI_TWO_PLACES 3.14

// Function to calculate the sqaure of a number
int computeSquare(int number) {
    return number * number;
}

// Function to input a number from the user
int userInputNum(void) {
    int input_num;
    scanf("%d", &input_num);
    return input_num;
}

// Function to print the calculated area
void outputArea(float number) {
    printf("%.1f\n\n", number);
}

int main(void) {
    float result;
    int choice, input_num, a, b;

    while (1) { // Infinite loop for menu
            printf("Find the area of a geometric shape:\n");
            printf("Press 1 to calculate the area of a circle\n");
            printf("Press 2 to calculate the area of a square\n");
            printf("Press 3 to calculate the area of a sphere\n");
            printf("Press 4 to calculate the area of an ellipse\n");
            printf("Press 0 to exit\n");
            printf("Enter your choice: ");
            choice = userInputNum();
    
            switch (choice) {
                case 1:
                    printf("Enter the radius: ");
                    input_num = userInputNum();
    //////////////////////////////////////////////////////////////////////////////
    //  Method 1: direct calculation of the area with hard-coded value for PI
    //////////////////////////////////////////////////////////////////////////////
                    result = 3.14 * input_num * input_num;
    //////////////////////////////////////////////////////////////////////////////
                    printf("Area of circle = ");
                    outputArea(result);
                    break;
                case 2:
                    printf("Enter the length of a side: ");
                    input_num = userInputNum();
    //////////////////////////////////////////////////////////////////////////////
    //  Method 2: use a function to compute the square of the input number
    //////////////////////////////////////////////////////////////////////////////
                    result = computeSquare(input_num);
    //////////////////////////////////////////////////////////////////////////////
                    printf("Area of square = ");
                    outputArea(result);
                    break;
                case 3:
                    printf("Enter the radius: ");
                    input_num = userInputNum();
    //////////////////////////////////////////////////////////////////////////////
    //  Method 3: use an object-like macro and a function-like macro
    //////////////////////////////////////////////////////////////////////////////
                    result = 4 * (PI_TWO_PLACES * SQUARE_NUM(input_num));
    //////////////////////////////////////////////////////////////////////////////
                    printf("Area of sphere = ");
                    outputArea(result);
                    break;
                case 4:
                    printf("Enter semi-major axis length: ");
                    a = userInputNum();
                    printf("Enter semi-minor axis length: ");
                    b = userInputNum();
    //////////////////////////////////////////////////////////////////////////////
    //  Method 4: use the math.h library version of PI
    //////////////////////////////////////////////////////////////////////////////
                    result = M_PI * a * b;
    //////////////////////////////////////////////////////////////////////////////
                    printf("Area of ellipse = ");
                    outputArea(result);
                    break;
                case 0:
                    printf("Exiting the program, bye!\n");
                    return 0;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        }
    
        return 0;
    }

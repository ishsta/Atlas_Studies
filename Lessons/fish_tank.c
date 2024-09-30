#include <stdio.h>
#include <math.h>

/******************************************************************************
*******************************************************************************
****  fish_tank.c  2 May 2024 by User Input                                ****
****                                                                       ****
****  Description: compute the amount of water needed to fill a fish tank. ****
****               Note: there are 231 cubic inches in 1 gallon.           ****
****  Input: length to the nearest 0.5 inches                              ****
****         width to the nearest 0.5 inches                               ****
****         height to the nearest 0.5 inches                              ****
****  Output: 1) print the user input values length, width, height to      ****
****          half an inch or 1 decimal place resolution                   ****
****          2) print the cubic inches of volume computed                 ****
****          3) finally, print the number of gallons needed to 2 places.  ****
*******************************************************************************
******************************************************************************/

int main(void) {

    float length, width, height;
    float volume_cubic_inches, amount_in_gallons;

    printf("Enter the length of the fish tank (to the nearest half inch): ");
    scanf("%f", &length);

    printf("Enter the width of the fish tank (to the nearest half inch): ");
    scanf("%f", &width);

    printf("Enter the height of the fish tank (to the nearest half inch): ");
    scanf("%f", &height);

    // Calculate volume in cubic inches, assign it to a variable. You will need this later.
    volume_cubic_inches = length * width * height;

    // Convert volume to gallons useing the known 231 cubic inches in a gallon
    amount_in_gallons = volume_cubic_inches / 231;

    // Repeat the user's input and display the volume in inches
    printf("The volume of a fish tank having length = %.1f width = %.1f and heigth = %.1f is %.2f cubic inches\n", length, width, height, volume_cubic_inches);

    // Display the amount of gallons
    printf("The amount of water needed to fill the fish tank = %.2f gallons\n", amount_in_gallons);

    // Display the result of the round() math.h function
    printf("The amount of water needed using the round function = %.2f gallons\n", round(amount_in_gallons));

    return 0;

}

/*

#include <math.h>: the standard library that includes the following functions for arithmetic operations:

    ceil(x): Returns the smallest integer greater than or equal to the given value x. It effectively rounds up to the nearest integer.
    floor(x): Returns the largest integer less than or equal to the given value x. It effectively rounds down to the nearest integer.
    fabs(x): Returns the absolute value of the given value x (i.e., the positive value of x).
    sqrt(x): Calculates the square root of the given value x.
    cbrt(x): Computes the cube root of the given value x.
    pow(x, y): Raises x to the power of y (i.e., computes x^y).
    exp(x): Computes e (Euler’s number) raised to the power of x.
    fmod(x, y): Computes the remainder when x is divided by y.
    log(x): Calculates the natural logarithm (base e) of x.
    log10(x): Computes the common logarithm (base 10) of x.
    modf(x, &y): Separates the fractional part of x and stores the integral part in the variable y.
    cos(x): Returns the cosine of the angle x (in radians).
    sin(x): Computes the sine of the angle x (in radians).
    tan(x): Calculates the tangent of the angle x (in radians).
    acos(x): Computes the arc cosine of x (in radians).
    asin(x): Calculates the arc sine of x (in radians).
    atan(x): Computes the arc tangent of x (in radians).
    cosh(x): Computes the hyperbolic cosine of x.
    sinh(x): Calculates the hyperbolic sine of x.Note: we are only going to discuss the use of one of these (round()) for this walkthrough.
    
*/
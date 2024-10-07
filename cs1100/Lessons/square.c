#include <stdio.h>

// Function declaration
double square(double x);

int main(void) {
    double result = square(5.8);
    printf("Square of 5.8 is: %lf\n", result);
    return 0;
}

// Function definition
double square(double x) {
    return x * x;
}
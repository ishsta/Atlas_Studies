#include <stdio.h> // standard input output
#include <math.h>

// Function to compute area and circumference
void computeCircleProperties(double* radius, double* area, double* circumference) {
    const double pi = 3.14159;
    *area = pi * (*radius) * (*radius);
    *circumference = 2 * pi * (*radius);
}

int main(void) {
    double circleRadius, circleArea, circleCircumference;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &circleRadius);

    computeCircleProperties(&circleRadius, &circleArea, &circleCircumference);

    printf("For a circle having radius: %.2lf\n", circleRadius);
    printf("Area: %.2lf\n", circleArea);
    printf("Circumference: %.2lf\n", circleCircumference);

    return 0;
}
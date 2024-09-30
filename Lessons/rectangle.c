#include <stdio.h>

void calculateRectangle(float length, float width, float *area, float *perimeter) {
    *area = length * width;
    *perimeter = 2 * (length + width);
}

int main(void) {
    float length, width, area, perimeter;

    printf("Enter the length of the rectangle: ");
    scanf("%f", &length);

    printf("Enter the width of the rectangle: ");
    scanf("%f", &width);

    calculateRectangle(length, width, &area, &perimeter);

    printf("Area %.2f\n", area);
    printf("Perimeter: %.2f\n", perimeter);

    return 0;
}
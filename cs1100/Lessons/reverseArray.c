#include <stdio.h>

void reverseArray(int *array_ptr, int size) {
    int *start = array_ptr;
    int *end = array_ptr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5,};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    reverseArray(numbers, size);

    printf("\nReversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
}
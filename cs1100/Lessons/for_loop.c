#include <stdio.h>

int main() {

    int sum = 0;

    for (int i = 1; i <= 100; i++) {
        sum += i;
    }

    printf("Sum of numbers from 1 too 100: %d \n", sum);

    return 0;

}
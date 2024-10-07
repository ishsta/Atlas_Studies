#include <stdio.h>

int main(){
    
    int sum = 0;
    int counter = 1;
    
    while (counter <= 100) {
        sum = sum + counter;
        counter += 1;
    }

    printf("Sum of numbers from 1 to 100: %d \n", sum);

    return 0;

}
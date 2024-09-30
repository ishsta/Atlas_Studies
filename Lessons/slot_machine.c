#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int bet;
    int balance;
    int randomNumber;

    srand(time(NULL));
    // print welcome statement

    while (balance > 0) {
        
        
        printf("How much do you want to bet?");
        scanf("%d", &bet);

        if (bet == 0) {
            // cashout
            break;
        }

        if (bet > balance || bet < 0) {
            // print error message
            continue;
        }

        randomNumber = rand() % 100 + 1;

        if (randomNumber < 50) {
            // loser message
        } else if (randomNumber >= 50 && randomNumber <=74) {
            // win bet back
        } else if (randomNumber >= 75 && randomNumber <= 94) {
            // win bet * 2
        } else {
            // JACKPOT!!! win bet * 3
        }

    }




}
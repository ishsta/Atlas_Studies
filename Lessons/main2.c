#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define VALID_BET 1
#define INVALID_BET 0

int main() {

    int playerBalanceQuarters = 80;
    float playerBalanceDollars;
    int randomNumber, bet;

    printf("Welcome to the Betting Game!\n");
    printf("You have $20 worth of quarters.\n");
    printf("\n");

    while (playerBalanceQuarters) {
      playerBalanceDollars = playerBalanceQuarters * .25;
       srand(time(NULL));
       randomNumber = rand() % 100 + 1;

       if ( playerBalanceQuarters == 0) {
        printf("Game Over\n");
        break;
       }

       printf("You have %d quarters (%.02f).\n", playerBalanceQuarters, playerBalanceDollars);
       printf("Enter the number of quarters to bet (or 0 to cash out): ");
       scanf("%d", &bet);

       if (bet == 0) {
        printf("Cashing out. You ended with $%.02f.\n", playerBalanceDollars);
        break;
       }

       if (bet > 0 && bet < playerBalanceQuarters) {
        printf("Reel stopped on the number: %d\n", randomNumber);

        if (randomNumber >= 95 && randomNumber <= 100) {
            printf("Jackpot! You triple your money!\n");
            playerBalanceQuarters += (bet * 3);
        } else if (randomNumber >= 75 && randomNumber <= 94) {
            printf("You double your money!");
            playerBalanceQuarters += (bet * 2);
        } else if (randomNumber >= 50 && randomNumber <= 74) {
            printf("You get your money back");
            playerBalanceQuarters += bet;
        } else {
            printf("You lose!");
        }
       } else if (bet < 0 || bet > playerBalanceQuarters || !isdigit(bet)) {
        printf("Invalid bet. Please enter a valid number of quarters.\n");
       }

    }

    return 0;
}

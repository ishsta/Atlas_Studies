#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define VALID_BET 1
#define INVALID_BET 0

int main() {

    int playerBalanceQuarters = 80;
    float playerBalanceDollars;
    char bet [100];
    int valid_bet;
    int randomNumber;

    printf("Welcome to the Betting Game! \n");
    printf("You have $20 worth of quarters. \n");
    printf("\n");

    while (playerBalanceQuarters) {
        playerBalanceDollars = (playerBalanceQuarters * .25);

        printf("You have %d quarters (%.2f). \n", playerBalanceQuarters, playerBalanceDollars);
        printf("Enter the number of quarters to bet (or 0 to cash out): ");
        fgets(bet, sizeof(bet), stdin);

        if (bet == "0") {
            printf("Cashing Out. You ended with $%.2f.\n", playerBalanceDollars);
            return 0;
        }

        valid_bet = VALID_BET;
        for (int i = 0; bet[i] != '\0'; i++) {
            if (bet[i] == '\n') {
                bet[i] = '\0';
                break;
            }
            if (!isdigit(bet[i]) && bet[i] != '-' || atoi(bet) > playerBalanceQuarters) {
                valid_bet = INVALID_BET;
                break;
            }
        }
        if (valid_bet) {
            playerBalanceQuarters -= atoi(bet);

            srand(time(NULL)); // Initialize random seed based on current time
            randomNumber = rand() % 100 + 1;

            printf("Reel stopped on the number: %d \n", randomNumber);

            if (randomNumber >= 95 && randomNumber <= 100) {
                printf("Jackpot! You triple your money! \n");
                printf("\n");
                playerBalanceQuarters += (atoi(bet) * 3);

            }else if (randomNumber >= 75 && randomNumber <= 94) {
                printf("You double your money! \n");
                printf("\n");
                playerBalanceQuarters += (atoi(bet) * 2);

            }else if (randomNumber >= 50 && randomNumber <= 74) {
                printf("You get your money back! \n");
                printf("\n");
                playerBalanceQuarters += atoi(bet);

            }else {
                printf("You lose! \n");
                printf("\n");
            }
        } else {
            printf("This is not a valid bet! \n");
            printf("\n");
        }

    }

    printf("Game Over");

    return 0;
}

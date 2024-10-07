/*
 * Player Gold Inventory
 *
 * This program allows players to manage their virtual gold inventory in a game.
 * Players can borrow gold up to a maximum limit, purchase items using their gold,
 * and save their progress when quitting the game. The program demonstrates the usage
 * of binary file I/O operations, including fread() and fwrite(), to store and retrieve
 * the player's gold amount.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "player_gold.dat"
#define MAX_BORROW 100000
#define MAX_GOLD 250000

int main(void) {
    int gold = 0;
    int choice;
    int amount;

    FILE *file = fopen(FILENAME, "rb");
    if (file != NULL) {
        fread(&gold, sizeof(int), 1, file);
        fclose(file);
    }

    while (1) {
        printf("Player's Gold: %d\n", gold);
        printf("1. Borrow Gold (Maximum: %d)\n", MAX_BORROW);
        printf("2. Purchase Item\n");
        printf("3. Save and Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the amount of gold to borrow: ");
                scanf("%d", &amount);
                if (amount <= MAX_BORROW && gold + amount <= MAX_GOLD) {
                    gold += amount;
                    printf("Gold borrowed successfully. Current gold: %d\n", gold);
                } else {
                    printf("Borrow failed. Maximum borrow limit or total gold limit exceeded.\n");
                }
                break;
            case 2:
                printf("Enter the cost of the item: ");
                scanf("%d",  &amount);
                if (amount <= gold) {
                    gold -= amount;
                    printf("Item purchased successfully! Current gold: %d\n", gold);
                } else {
                    printf("Insufficient gold to make the purchase.\n");
                }
                break;
            case 3:
                file = fopen(FILENAME, "wb");
                if (file != NULL) {
                    fwrite(&gold, sizeof(int), 1, file);
                    fclose(file);
                    printf("Game data saved. Quitting the game.\n");
                } else {
                    printf("Error saving game data.\n");
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}
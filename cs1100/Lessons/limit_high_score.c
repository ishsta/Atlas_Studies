#include <stdio.h>
#include <limits.h> // Include this library for integer limits
#include <stdlib.h> // Include this library for atoi

/*
 * File: limit_high_score.c
 * Description: This program demonstrates how to safely limit a video game 
 *              high score to prevent integer overflow. It prompts the user 
 *              to enter points earned and updates the current score with them.
 *              If the score reaches the maximum high score, the game ends.
 */

#define MAX_HIGH_SCORE 1000000
#define GAME_RUNNING 0
#define GAME_OVER 1

int main(void) {
    int current_score = 0; // Initialize the current score to 0
    int points_earned;
    int game_status = GAME_RUNNING; // Initialize the game status to running
    char points_earned_str[20];
    do {
        // Prompt the user to enter points earned
        printf("Enter points earned (0 to exit): ");
        scanf("%s", points_earned_str); // Read points earned from user
        points_earned = atoi(points_earned_str);

        if (points_earned == 0) {
            game_status = GAME_OVER; // If the user enters 0, set the game status to game over
        } else if (points_earned < 0) {
            // If the user enters a negative value, print an error message
            printf("Invalid input. Points earned cannot be negative.\n");
        } else if (current_score > INT_MAX - points_earned) {
            // If adding the points earned to the current score would cause integer overflow,
            // print an error message indicating that the score cannot exceed the maximum score
            printf("Error: Integer overflow detected. Score cannot exceed %d.\n", MAX_HIGH_SCORE);
        } else {
            current_score += points_earned; // Add the points earned to the current score
            printf("Current score: %d\n", current_score); // Print the updated current score

            if (current_score >= MAX_HIGH_SCORE) {
                // If the current score reaches or exceeds the maximum high score,
                // print a congratulatory message and set the game status to game over
                printf("Congratulations! You have reached the maximum high score of %d.\n", MAX_HIGH_SCORE);
                game_status = GAME_OVER;
            }
        }
    } while (game_status == GAME_RUNNING); // Continue the loop while the game status is running

    return 0;
}
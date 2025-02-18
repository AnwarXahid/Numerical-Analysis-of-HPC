/**
 * Anwar Hossain Zahid
 * Iowa State University
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Runs the Monty Hall simulation.
 */
int main() {
    srand(time(NULL));  // Seed for random number generation

    int prize = rand() % 3;  // Randomly place the prize behind a door (0,1,2)
    int pick = -1;

    // User selects a door
    while (pick < 0 || pick > 2) {
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("   ** Monty Hall Simulator **\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Pick a door (0, 1, or 2): ");
        scanf("%d", &pick);
    }

    printf("\nYou chose Door %d.\n", pick);

    // Host reveals a non-prize door
    int revealed;
    for (int i = 0; i < 3; i++) {
        if (i != pick && i != prize) {
            revealed = i;
            break;
        }
    }

    printf("Monty opens Door %d, which has no prize!\n", revealed);

    // Ask user if they want to switch
    int change = -1;
    while (change != 0 && change != 1) {
        printf("\nStay with Door %d (press 0) or switch to another Door (press 1)? ", pick);
        scanf("%d", &change);
    }

    // Update the final pick
    int final_pick = (change == 1) ? (3 - pick - revealed) : pick;
    printf("\nYou %s to Door %d.\n", (change == 1) ? "switched" : "stayed", final_pick);

    // Check result
    if (final_pick == prize) {
        printf("\n*** CONGRATULATIONS! You won! *** 🎉\n");
    } else {
        printf("\n--- Sorry, you lost. --- 😢\n");
    }

    printf("The prize was behind Door %d.\n", prize);
    return 0;
}

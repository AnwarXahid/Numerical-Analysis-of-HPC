/*
 * GenerateList.c
 * Generates a linked list with random ASCII letters
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "node.h"

void GenerateList(node** head, const int num_nodes) {
    node* temp;
    srand(time(NULL));  // Seed random

    printf("\nGenerated List: ");
    for (int i = 0; i < num_nodes; i++) {
        temp = (node*)malloc(sizeof(node));

        // Generate random upper/lowercase letters
        int ascii = (rand() % 52) + 65;
        if (ascii > 90) ascii += 6;  // Skip non-letter ASCII

        temp->value = (char)ascii;
        temp->position = 0;

        printf("%c ", temp->value);

        temp->next = *head;
        *head = temp;
    }
    printf("\n");

    // Assign positions
    node* ptr = *head;
    int pos = 1;
    while (ptr != NULL) {
        ptr->position = pos++;
        ptr = ptr->next;
    }
}


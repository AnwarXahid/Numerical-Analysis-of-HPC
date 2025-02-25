/*
 * Print.c
 * Prints the linked list forward and in reverse
 */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void PrintLine(const int pos, const char val, const node* head, const node* next) {
    printf(" |%3d |  %c | %15p | %15p |\n", pos, val, head, next);
}

void Print(const int forward, const node* head) {
    if (head == NULL) {
        printf(" List is empty.\n\n");
        return;
    }

    printf("\n ---------------------------------------------\n");
    printf(" |Pos:|Val:| Address: | Next: |\n");
    printf(" ---------------------------------------------\n");

    if (forward)
        PrintList(head);
    else
        ReversePrintList(head);

    printf(" ---------------------------------------------\n");
}

void PrintList(const node* head) {
    PrintLine(head->position, head->value, head, head->next);
    if (head->next != NULL)
        PrintList(head->next);
}

void ReversePrintList(const node* head) {
    if (head->next != NULL)
        ReversePrintList(head->next);
    PrintLine(head->position, head->value, head, head->next);
}


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Push(char input, node** top) {
    node* temp = (node*)malloc(sizeof(node));
    temp->value = input;
    temp->next = *top;
    temp->position = 1;

    node* ptr = *top;
    while (ptr != NULL) {
        ptr->position++;
        ptr = ptr->next;
    }

    *top = temp;
}


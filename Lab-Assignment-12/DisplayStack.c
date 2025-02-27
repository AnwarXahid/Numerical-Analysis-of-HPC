#include <stdio.h>
#include "stack.h"

void DisplayStack(node* top) {
    if (top == NULL) {
        printf(" Stack is empty.\n");
        return;
    }

    printf("\n ---------------------------------------------\n");
    printf(" |Pos:|Val:| Address: | Next: |\n");
    printf(" ---------------------------------------------\n");

    node* ptr = top;
    while (ptr != NULL) {
        printf(" |%3d | %c | %p | %p |\n", ptr->position, ptr->value, ptr, ptr->next);
        ptr = ptr->next;
    }

    printf(" ---------------------------------------------\n");
}


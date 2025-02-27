#include <stdlib.h>
#include "stack.h"

void Pop(node** top, char* output) {
    if (*top == NULL) return;

    node* temp = *top;
    *output = temp->value;
    *top = temp->next;

    free(temp);

    node* ptr = *top;
    while (ptr != NULL) {
        ptr->position--;
        ptr = ptr->next;
    }
}


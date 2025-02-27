#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void DeleteStack(node** top) {
    while (*top != NULL) {
        node* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    printf("\n Stack deleted. Goodbye!\n");
}


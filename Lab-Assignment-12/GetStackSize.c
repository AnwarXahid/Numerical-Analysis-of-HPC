#include <stddef.h>   // This defines NULL
#include "stack.h"

void GetStackSize(node* top, int* size) {
    if (top == NULL) {   // This is now fine
        *size = 0;
    } else {
        *size = top->position;
    }
}


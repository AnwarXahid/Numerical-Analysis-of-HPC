#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int QueryOption() {
    int option;
    printf(" ENTER CHOICE: ");
    if (scanf("%d", &option) != 1) {
        printf("Invalid input! Defaulting to option 0.\n");
        option = 0;
        while (getchar() != '\n');  // Clear input buffer
    }
    return option;
}

void ExecuteOption(int option, node** top) {
    char value;
    int size;

    switch (option) {
        case 0:
            DisplayOptions();
            break;
        case 1:
            printf(" Enter character: ");
            if (scanf(" %c", &value) != 1) {
                printf("Invalid input! Skipping push.\n");
                while (getchar() != '\n');  // Clear input buffer
                break;
            }
            Push(value, top);
            break;
        case 2:
            if (*top != NULL) {
                Pop(top, &value);
                printf(" Popped character = '%c'\n", value);
            } else {
                printf(" Stack is empty.\n");
            }
            break;
        case 3:
            if (*top != NULL) {
                printf(" Top character = '%c'\n", Peek(*top));
            } else {
                printf(" Stack is empty.\n");
            }
            break;
        case 4:
            DisplayStack(*top);
            break;
        case 5:
            GetStackSize(*top, &size);
            printf(" Stack size = %d\n", size);
            break;
        case 6:
            break;
        default:
            printf(" Invalid option! Try again.\n");
    }
}


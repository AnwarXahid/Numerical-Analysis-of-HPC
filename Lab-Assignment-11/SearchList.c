/*
 * SearchList.c
 * Searches the list based on ASCII value (case-sensitive)
 */

#include <stdio.h>
#include "node.h"

void SearchList(const node* head, const char key) {
    int found = 0;
    while (head != NULL) {
        if (head->value == key) {
            printf(" Found '%c' at Position: %d\n", key, head->position);
            found = 1;
        }
        head = head->next;
    }
    if (!found)
        printf(" '%c' not found in list.\n", key);
}


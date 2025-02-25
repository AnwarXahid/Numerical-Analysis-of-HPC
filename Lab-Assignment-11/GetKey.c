/*
 * GetKey.c
 * Prompt user for character to search
 */

#include <stdio.h>

char GetKey() {
    char key;
    printf("\nEnter character to search: ");
    scanf(" %c", &key);  // Space before %c to handle newline
    return key;
}


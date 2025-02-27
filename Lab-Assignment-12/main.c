/*
 * main.c
 * Stack Driver Program
 * Written by Anwar Hossain Zahid
 * Department of Computer Science, Iowa State University
 */

#include <stdio.h>
#include "stack.h"

int main() {
    node* top = NULL;
    int option = 0;

    while (option != 6) {
        ExecuteOption(option, &top);
        option = QueryOption();
    }

    DeleteStack(&top);
    return 0;
}


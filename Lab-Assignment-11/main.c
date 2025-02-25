/*
 * main.c
 * Linked List Assignment - Using Characters
 * Written by Anwar Hossain Zahid
 * Department of Computer Science, Iowa State University
 */

#include <stdio.h>
#include "node.h"

int GetNumberOfNodes() {
    int num;
    printf("Enter the number of nodes: ");
    scanf("%d", &num);
    return num;
}

int main() {
    node* head = NULL;
    const int num_nodes = GetNumberOfNodes();

    GenerateList(&head, num_nodes);

    // Print List
    Print(1, head);  // Forward Print
    Print(0, head);  // Reverse Print

    // Search for a character based on ASCII
    if (num_nodes > 0) {
        char key = GetKey();
        SearchList(head, key);
    }

    // Delete List
    DeleteList(&head);
    return 0;
}


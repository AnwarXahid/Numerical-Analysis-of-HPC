/*
 * stack.h
 * Stack Implementation Using Characters
 * Written by Anwar Hossain Zahid
 * Department of Computer Science, Iowa State University
 */

#ifndef STACK_H
#define STACK_H

typedef struct node {
    char value;    // Character value (supports both upper/lower case)
    int position;  // Position in stack (1 = top)
    struct node* next;
} node;

void DisplayOptions();
int QueryOption();
void ExecuteOption(int option, node** top);
void Push(char input, node** top);
void Pop(node** top, char* output);
char Peek(node* top);
void DisplayStack(node* top);
void GetStackSize(node* top, int* size);
void DeleteStack(node** top);

#endif


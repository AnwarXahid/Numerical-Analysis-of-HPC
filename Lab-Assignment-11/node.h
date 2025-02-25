/*
 * node.h
 * Linked List Assignment - Using Characters
 * Written by Anwar Hossain Zahid
 * Department of Computer Science, Iowa State University
 */

#ifndef __NODE_H__
#define __NODE_H__

typedef struct node node;
struct node {
    int position;
    char value;     // Store character
    node* next;
};

// Function Prototypes
int GetNumberOfNodes();
void GenerateList(node** head, const int num);
void Print(const int forward, const node* head);
void PrintList(const node* head);
void ReversePrintList(const node* head);
char GetKey();
void SearchList(const node* head, const char key);
void DeleteList(node** head);

#endif


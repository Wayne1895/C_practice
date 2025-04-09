#ifndef STACK_BYLINKEDLIST_H
#define STACK_BYLINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
};

void push(int num);
int pop(int *value);
void printstack();


#endif
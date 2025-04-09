#include <stdio.h>
#include <stdlib.h>
#include "stack_bylinkedlist.h"

struct Node *head = NULL;

void push(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int pop(int *result){
    if(head == NULL){
        printf("Stack is empty\n");
        return 0;
    }
    *result = head->data;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return 1;
}
void printstack(){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = head;
    while(temp){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
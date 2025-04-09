#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

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

int main() {
    push(10);
    push(20);
    push(30);

    printf("Current stack: ");
    printstack();

    int value;
    while (pop(&value)) {
        printf("Popped: %d\n", value);
    }

    // 多試一次空堆疊 pop
    pop(&value);

    printf("Stack after pop: ");
    printstack();

    return 0;
}
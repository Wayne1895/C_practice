#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertNode(struct Nodeint data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printlist(){
    if(head == NULL){
        printf("Linkedlist不存在\n");
        return;
    }
    else{
        struct Node *temp = head;
        while(temp->next){
            printf("%d->",temp->data);
            temp = temp->next;
        }
        printf("%d->NULL\n",temp->data);

    }
}

void deleteNode(int data){
    if(head == NULL){
        printf("Linkedlist 不存在\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (temp->data == data) {
        head = temp->next;
        free(temp);
        printf("已刪除節點 %d\n", data);
        return;
    }
    while(temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Linkedlist 中找不到%d\n",data);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("已刪除節點%d\n",data);
}

void freeList(){
    if(head == NULL){
        printf("Linkedlist 不存在\n");
        return;
    }
    while(head != NULL){
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL; // 確保 head 指向 NULL
    printf("已刪除Linkedlist\n");
}
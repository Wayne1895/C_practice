#include <stdlib.h>
#include <stdio.h>
#include "hash_map.h"

Node* hashtable[TABLE_SIZE];

int hash_function(int key){
    return (key% TABLE_SIZE + TABLE_SIZE)%TABLE_SIZE;
}

void insert(int key){
    int index = hash_function(key);
    Node *temp_Node = hashtable[index];
    while(temp_Node){
        if(temp_Node->key == key){
            temp_Node->count++;
            return;
        }
        temp_Node = temp_Node->next;
    }
    temp_Node = (Node*)malloc(sizeof(Node));
    temp_Node->key = key;
    temp_Node->count = 1;
    temp_Node->next = hashtable[index];
    hashtable[index] = temp_Node;
}

int search(int key){
    int index = hash_function(key);
    Node *temp = hashtable[index];
    while(temp){
        if(temp->key == key){
            temp->count--;
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void free_hashtable(void){
    Node *temp_Node;
    for(int i = 0;i<TABLE_SIZE;i++){
        temp_Node = hashtable[i];
        while(temp_Node){
            Node *temp = temp_Node;
            temp_Node = temp_Node->next;
            free(temp);
        }
        hashtable[i] = NULL;
    }
}

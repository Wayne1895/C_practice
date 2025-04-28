#ifndef  HASH_MAP_H
#define HASH_MAP_H

#define TABLE_SIZE 1069
typedef struct Node{
    int key;
    int count;
    struct Node* next;
}Node;
extern Node* hashtable[TABLE_SIZE];

int hash_function(int key);
void insert(int key);
int search(int key);
void free_hashtable(void);

#endif
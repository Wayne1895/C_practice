#include <stdlib.h>
typedef struct Node{
    int* arr;
    int count;
    struct Node* next;
}node;

#define HASHTABLE_SIZE 1099
#define base 29
int hash_function(int *arr, int len){
    int h = 0;
    for (int i = 0; i < len; i++) {
        h = (h * base + arr[i]) % HASHTABLE_SIZE;
    }
    return h;
}

node* hashtable[HASHTABLE_SIZE];
int cmp_arry(int* a, int* b, int len){
    for(int i = 0; i <len ;i++){
        if(a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

void insert_row(int* arr,int len){
    int hash = hash_function(arr, len);
    node *temp = hashtable[hash];
    while(temp){
        if(cmp_arry(temp->arr , arr, len)){
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    node *newnode = (node*)malloc(sizeof(node));
    newnode->arr = (int*)malloc(sizeof(int)*len);
    memcpy(newnode->arr, arr, sizeof(int)*len);
    newnode->count = 1;
    newnode->next = hashtable[hash];
    hashtable[hash] = newnode;
}
int find_col(int *arr, int len){
    int hash = hash_function(arr, len);
    node *temp = hashtable[hash];
    
    while(temp){
        if(cmp_arry(temp->arr , arr,len)){
            return temp->count;
        }
        temp = temp->next;
    }
    return 0;
}
void clear_hashtable(int n) {
    for (int i = 0; i < n; i++) {
        node* cur = hashtable[i];
        while (cur) {
            node* next = cur->next;
            free(cur->arr);
            free(cur);
            cur = next;
        }
        hashtable[i] = NULL;
    }
}

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    clear_hashtable(HASHTABLE_SIZE); //先清空hashtable
    int result = 0;
    for(int i =0; i <gridSize; i++){
        insert_row(grid[i], gridSize);
    }
    for(int i = 0; i<  gridSize;i++){
        int* col = (int*)malloc(sizeof(int)*gridSize);
        for(int j = 0; j<gridSize;j++){
            col[j] = grid[j][i];
        }
        result+= find_col(col, gridSize);
        free(col);
    }
    return result;
    
}
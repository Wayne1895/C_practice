#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int priority;
    int data;
}Node;

typedef struct{
    Node* heap;
    int size;
    int capacity;
}PriorityQueue;

#define INITIAL_CAPACITY 19

void InitialPriorityqueue(PriorityQueue *pq){
    pq->heap = (struct Node*)malloc(sizeof(struct Node)*INITIAL_CAPACITY);
    pq->size = 0;
    pq->capacity = INITIAL_CAPACITY;
}

void swap(Node *a, Node *b){
    Node TEMP = *a;
    *a = *b;
    *b = TEMP;
}

void EnsureCapacity(PriorityQueue *pq){
    if(pq->size >= pq->capacity){
        pq->capacity *= 2;
        pq->heap = (Node *) realloc(pq->heap,sizeof(Node)*(pq->capacity));
    }

}

void push(PriorityQueue *pq ,int priority, int data){
    EnsureCapacity(pq);
    int i = pq->size++;
    pq->heap[i].priority = priority; // (*(pq->heap + i )).priority
    (pq->heap+i)->data = data; //pq->heap[i] ≡ *(pq->heap + i)

    //heapify (bottom up)
    while(i > 0){
        int parent = (i-1)/2;
        if(pq->heap[i].priority > pq->heap[parent].priority){
           swap(&pq->heap[i], &pq->heap[parent]); //swap(pq.heap+i, pq.heap+parent);
           i = parent;
        }
        else break;
    }
}
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

void initialPriorityQueue(PriorityQueue *pq){
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

struct Node pop(PriorityQueue *pq){
    if(pq->size == 0){
        fprintf(stderr,"Priority Queue為空\n");
        exit(EXIT_FAILURE);
    }
    Node MAX = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    
    int i = 0;
    while(1){
        int left = 2*i+1;
        int right = 2*i+2;
        int large_one = i;
        if((left < pq->size) && pq->heap[left].priority > pq->heap[large_one].priority){
            large_one = left;
        }
        if((right < pq->size) && pq->heap[right].priority > pq->heap[large_one].priority){
            large_one = right;
        }
        if(large_one == i){
            break;
        }
        swap(&pq->heap[i], &pq->heap[large_one]);
        i = large_one;
    }
    return MAX;
}

Node peek(PriorityQueue *pq){
    if(pq->size == 0){
        fprintf(stderr, "Priority Queue 為空\n");
        exit(EXIT_FAILURE);
    }
    return pq->heap[0];
}

void freePriorityQueue(PriorityQueue *pq){
    free(pq->heap);
    pq->heap = NULL;
    pq->capacity = 0;
    pq->size = 0;
}


int main(){
    PriorityQueue MAXHEAP;
    initialPriorityQueue(&MAXHEAP);
    push(&MAXHEAP, 1, 100);
    push(&MAXHEAP, 100, 1);
    Node first_pop = pop(&MAXHEAP);
    printf("Priority: %d, Data: %d\n", first_pop.priority, first_pop.data);

    push(&MAXHEAP, 5, 100);
    push(&MAXHEAP, 3, 200);
    push(&MAXHEAP, 10, 300);
    while(MAXHEAP.size > 0){
        Node n = pop(&MAXHEAP);
        printf("Priority: %d, Data: %d\n", n.priority, n.data);
    }
    freePriorityQueue(&MAXHEAP);
    return 0;

}
#include <stdio.h>
#include "stack_bylinkedlist.h"

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
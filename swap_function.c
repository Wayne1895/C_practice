#include <stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int first = 100;
    //int *p =&first;
    int second = 9;
    swap(&first, &second);//swap(p, &second);
    printf("first的值%d,second的值%d", first, second);
    return 0;
}
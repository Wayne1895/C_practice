#include <stdio.h>
#include <stdlib.h>

void reversearray(int *array, int n){
    int *left = array;
    int *right = array+n-1;
    while(left < right){
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }

}

int main(){ 
    printf("輸入陣列大小\n");
    int n = 0;
    scanf("%d", &n);
    int *newarr = (int *)malloc(sizeof(int) * n);
    if(newarr == NULL){
        printf("記憶體分配失敗\n");
        return 0;
    }
    printf("輸入%d個整數\n",n);
    for(int i = 0;i < n ;i++){
        scanf("%d", &newarr[i]);
    }

    for(int i = 0; i< n; i++){
        if( i < n-1){
        printf("%d, ",*(newarr+i));
        }
        else{
            printf("%d", *(newarr+i));
        }
    }
    printf("\n");
    reversearray(newarr, n);

    for(int i = 0; i< n; i++){
        if( i < n-1){
        printf("%d, ",*(newarr+i));
        }
        else{
            printf("%d", *(newarr+i));
        }
    }
    free(newarr);
    return 0;

}
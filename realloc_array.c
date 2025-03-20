#include <stdio.h>
#include <stdlib.h>

int main(){
    int array_size = 0;
    printf("輸入一正整數決定陣列大小:\n");
    scanf("%d", &array_size);
    if(array_size <= 0){
        printf("錯誤\n");
        return 0;
    }
    int *array = (int *)malloc(array_size * sizeof(int));
    if(array == NULL){
        printf("記憶體分配失敗\n");
        return 0;
    }
    
    printf("====輸入%d個整數====\n",array_size);
    int sum = 0;
    for(int i = 0; i < array_size; i++){
        printf("輸入第%d個整數:\n",i+1);
        scanf("%d",&array[i]);
        sum += array[i];
    }
    printf("是否需要增加更多數據?Y/N\n");
    char decision;
    scanf(" %c",&decision);
    if(decision == 'Y' ||  decision == 'y' ){
        int add_array = 0;
        printf("輸入想要加入的數據數量:\n");
        scanf("%d", &add_array);
        array_size += add_array;
        int *temp = (int *)realloc(array, array_size * sizeof(int));
        if (temp == NULL) {
            printf("記憶體擴展失敗\n");
            free(array);
            return 0;
        }
        array = temp;
        for(int i = 0; i < add_array; i++){
            printf("輸入想加入的第%d個整數:\n",i+1);
            scanf("%d",&array[array_size-add_array+i]);
            sum += array[array_size - add_array + i];
        }

    }
    printf("總和等於:%d，平均值等於:%.2f\n",sum,(sum/ (float)array_size));
    free(array);
    return 0;

}
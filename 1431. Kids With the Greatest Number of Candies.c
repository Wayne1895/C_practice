#include <stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max = 0;
    for(int i=0;i<candiesSize;i++){
        if(candies[i]>max){
            max = candies[i];
        }
    }

    bool *result = (bool *)malloc(candiesSize * sizeof(bool));
    for(int i=0;i<candiesSize;i++){
        result[i] = (candies[i] + extraCandies) >= max; 
    } 
    *returnSize = candiesSize;
    return result;
}
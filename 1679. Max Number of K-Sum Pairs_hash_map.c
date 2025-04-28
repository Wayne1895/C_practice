#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"

int maxOperations(int* nums, int numsSize, int k) {
    for (int i = 0; i < TABLE_SIZE; i++) hashtable[i] = NULL; // 初始化哈希表

    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        int target = k - nums[i];
        if (search(target)) {
            count++;
        } else {
            insert(nums[i]);
        }
    }
    free_hashtable();
    return count;
}
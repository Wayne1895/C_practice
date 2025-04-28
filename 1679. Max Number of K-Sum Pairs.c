int compare(const void* a, const void*b){
    return (*(int*) a-*(int*) b);
}

int maxOperations(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), compare);

    int i = 0, j = numsSize-1;
    int count = 0;
    while(i < j){
        int total = nums[i] + nums[j];

        if(total == k){
            i++;
            j--;
            count++;
        }
        else if (total < k){
            i++;
        }
        else{
            j--;
        }
    }
    return count;
}
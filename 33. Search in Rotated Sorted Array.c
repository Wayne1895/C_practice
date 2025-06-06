int search(int* nums, int numsSize, int target) {
    int left=0,right=numsSize-1;
    
    while(left<=right){
        int mid = (left+right)/2;
        if(target == nums[mid]){
            return mid;
        }
        if(nums[left]<=nums[mid]){
            if(target>=nums[left] && target<nums[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        else{
            if(target>nums[mid] && target<=nums[right]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    }
    return -1;
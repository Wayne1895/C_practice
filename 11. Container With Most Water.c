int max(int a, int b){
    return a>b?a:b;
}
int min(int a, int b){
    return a<b?a:b;
}

int maxArea(int* height, int heightSize) {
    int maxwater = 0;
    int l = 0, r = heightSize-1;
    while(l < r){
        int water_contain = (r-l)*min(height[l], height[r]); 
        maxwater = max(maxwater, water_contain);
        if(height[l] < height[r]){
            l++;
        }
        else{
            r--;
        }
    }
    return maxwater;

    
}
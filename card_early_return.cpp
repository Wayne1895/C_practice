#include <vector>
using namespace std;
void quicksort(vector<int>& array, int left, int right){
    if(left>=right){
        return;
    }
    int i = left, j=left;
    int pivot = array[right];
    while(j < right){
        if(array[j]<pivot){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
        j++;
    }
    int temp = array[i];
    array[i] = array[right];
    array[right] = temp;
    quicksort(array, left, i-1);
    quicksort(array, i+1, right);

}

int f(const vector<int>& input){
    
    vector<int> suits(5);
    vector<int>  nums(5);
    
    for(int i=0;i<5;i++){
        suits[i] = ((input[i]>>8)&0xf);
        nums[i] = (input[i]&0xff);
    }

    quicksort(suits, 0, 4);
    quicksort(nums, 0, 4);

    int suit_count[4] = {0};
    int num_count[13] = {0};
    for(int i=0;i<5;i++){
        suit_count[suits[i]-1]++;
        num_count[nums[i]-2]++;
    }

    bool isFlush = false;
    bool isThreeofakind = false;
    bool isOnePair = false;
    for(int i=0;i<4;i++){
        if(suit_count[i] == 5){isFlush = true;}
    }
    
    for(int i=0;i<13;i++){
        if(num_count[i] == 4){return 3;}
        if(num_count[i]== 3){isThreeofakind = true;}
        if(num_count[i] == 2){
            isOnePair = true;
            for(int j=i+1;j<13;j++){
                if(num_count[j] == 2){return 8;}
            }
        }
        int count = 0;
        int j = i;
        while(j <13 && num_count[j]==1){
            j++;
            count++;
        }
        if(count == 5){
            if(isFlush){
                if(nums[0]==10){return 1;}
                else{return 2;}
            }
            return 6;
        }
    }
    if (num_count[12] && num_count[0] && num_count[1] &&
        num_count[2] && num_count[3]) {
        if(isFlush){return 2;}
        else{return 6;}          
    }
    if(isFlush){return 5;}
    if(isThreeofakind && isOnePair){return 4;}
    if(isThreeofakind){return 7;}
    if(isOnePair){return 9;}
    return 10;  

}
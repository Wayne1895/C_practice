#include <vector>
using namespace std;
int f(const vector<int>& input){
    
    int JOKER = 0;
    vector<int> suits(5);
    vector<int>  nums(5);
    int suit_count[6] = {0};
    int num_count[15] = {0};
    for(int i=0;i<5;i++){
        if (input[i]==0x50f || input[i]==0x610){
            JOKER++;
        }
        suits[i] = ((input[i]>>8)&0xf);
        nums[i]  = (input[i]&0xff);
        suit_count[suits[i]-1]++;
        num_count[nums[i]-2]++;
    }
    bool isRF = false;
    bool isStraightFlush = false;
    bool isFour = false;
    bool isFullHouse = false;
    bool isFlush = false;
    bool isStraight = false;
    bool isThree = false;
    bool isTwoPair = false;
    bool isOnePair = false;

    if(JOKER == 0){
        
        for(int i =0;i<4;i++){
            if(suit_count[i] == 5){isFlush = true;}
        }
        
        int Royal_count = 0;
        int Royal_array[] = {8, 9, 10, 11, 12};
        for(int i :Royal_array){
            if(num_count[i]==1){
                Royal_count++;
            }    
        }
        if(Royal_count==5 && isFlush){isRF = true;}
        for(int i=0;i<8;i++){
            int count = 0;
            int j = i;
            while(num_count[j]==1){
                count++;
                j++;
            }
            if(count == 5){
                isStraight = true;
                break;
            }
        }
        int A_count = 0;
        int A_array[] = {12, 0, 1, 2, 3};
        for(int i:A_array){
            if(num_count[i]==1){
                A_count++;
            }
        }
        if(A_count == 5){isStraight = true;}
        if(isStraight && isFlush){isStraightFlush = true;}
        
        int pairs = 0;
        for(int i=0;i<13;i++){
            if(num_count[i]==4){isFour = true;break;}
            if(num_count[i]==3){isThree = true;}
            if(num_count[i]==2){pairs++;}
        }
        if(pairs==2){isTwoPair = true;}
        if(pairs==1){isOnePair = true;}
        if(isThree && isOnePair){isFullHouse = true;}


    }
    if(JOKER == 1){
        
        for(int i =0;i<4;i++){
            if(suit_count[i] == 4){isFlush = true;}
        }
        
        int Royal_count = 0;
        int Royal_array[] = {8, 9, 10, 11, 12};
        for(int i :Royal_array){
            if(num_count[i]==1){
                Royal_count++;
            }    
        }
        if(Royal_count==4 && isFlush){isRF = true;}
        for(int i=0;i<8;i++){
            int remain = JOKER;
            int count = 0;
            int j = i;
            while(num_count[j]==1 || (num_count[j]==0 && remain>0)){
                if(num_count[j]==0){remain--;}
                count++;
                j++;
            }
            if(count == 5){
                isStraight = true;
                break;
            }
        }
        int A_count = 0;
        int A_array[] = {12, 0, 1, 2, 3};
        for(int i:A_array){
            if(num_count[i]==1){
                A_count++;
            }
        }
        if(A_count == 4){isStraight = true;}
        if(isStraight && isFlush){isStraightFlush = true;}
        
        int pairs = 0;
        for(int i=0;i<13;i++){
            if(num_count[i]>=3){isFour = true;break;}
            if(num_count[i]==2){
                pairs++;
            }
        }
        if(pairs==2){isFullHouse = true;}
        if(pairs==1){isThree = true;}
        if(pairs==0){isOnePair = true;}
    }

    if(JOKER == 2){
        
        for(int i =0;i<4;i++){
            if(suit_count[i] == 3){isFlush = true;}
        }
        
        int Royal_count = 0;
        int Royal_array[] = {8, 9, 10, 11, 12};
        for(int i :Royal_array){
            if(num_count[i]==1){
                Royal_count++;
            }    
        }
        if(Royal_count==3 && isFlush){isRF = true;}
        for(int i=0;i<8;i++){
            int remain = JOKER;
            int count = 0;
            int j = i;
            while(num_count[j]==1 || (num_count[j]==0 && remain>0)){
                if(num_count[j]==0){remain--;}
                count++;
                j++;
            }
            if(count == 5){
                isStraight = true;
                break;
            }
        }
        int A_count = 0;
        int A_array[] = {12, 0, 1, 2, 3};
        for(int i:A_array){
            if(num_count[i]==1){
                A_count++;
            }
        }
        if(A_count == 3){isStraight = true;}
        if(isStraight && isFlush){isStraightFlush = true;}
        
        int pairs = 0;
        for(int i=0;i<13;i++){
            if(num_count[i]>=2){
                isFour = true;
                pairs++;
                break;}
        }
        if(pairs==0){isThree = true;}
        
    }
    if(isRF){return 1;}
    if(isStraightFlush){return 2;}
    if(isFour){return 3;}
    if(isFullHouse){return 4;}
    if(isFlush){return 5;}
    if(isStraight){return 6;}
    if(isThree){return 7;}
    if(isTwoPair){return 8;}
    if(isOnePair){return 9;}
    return 10;

}
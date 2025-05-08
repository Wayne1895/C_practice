#include <vector>
#include <string>
using namespace std;

string f(const vector<int>& input){
    if (input.empty()) return "";
    int len = input.size();
    vector<int> array;
    array.push_back(input[0]);

    for(int i=1;i<len;i++){
        int index = array.size();
        array.push_back(input[i]); 
        int parent = (index-1)/2;
        
        while(index>0){
            if( array[index] < array[parent]){
                int temp = array[parent];
                array[parent] = array[index];
                array[index] = temp;
                index = parent;
                parent = (parent-1)/2;
            }
            else{
                break;
            }
        }
    }
    string result;
    for(int i = 0;i<len;i++){
        int index = 0;
        result+= to_string(array[0]);
        if(i<len-1){
            result+=' ';
        }
        array[0] = array.back();
        array.pop_back();
        while(1){
            int left = 2*index+1;
            int right = 2*index+2;
            int small_one = index;
            if(left < array.size() && array[left] < array[index]){
                small_one = left;
            }
            if(right < array.size() && array[right] < array[index]){
                small_one = right;
            }
            if(small_one == index){
                break;
            }
            int temp = array[small_one];
            array[small_one] = array[index];
            array[index] = temp;
            index = small_one;

        }
    }
    return result;
}
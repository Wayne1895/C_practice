#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    vector <int> array;
    cout<<"輸入數字個數"<<endl;
    int n;
    cin>>n;
    cout<<"輸入"<<n<<"個數字"<<endl;
    for(int i = 1;i<=n;i++){
        int num;
        cin>>num;
        array.push_back(num);
    }
    vector<int>::iterator max_num = max_element(array.begin(),array.end()); //auto max_num = max_element(vector.begin(),vector.end());
    cout<<"最大值為"<<*max_num<<endl;

}
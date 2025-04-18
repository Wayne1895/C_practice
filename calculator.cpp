#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Calculator{
public:
    int add(int a, int b){
        return a+b;
    };
    int subtract(int a, int b){
        return a-b;
    };
    int absDiff(int a, int b){
        return a > b?(a-b):(b-a);
    };

};

int main(){
    Calculator abc;
    cout<<"輸入計算式"<<endl;

    string equation;
    getline(cin, equation);

    bool isABS = false;
    if((equation.front() == '|') && (equation.back() == '|')){
        isABS = true;
        equation = equation.substr(1, equation.length() - 2);
    }

    size_t pos;
    char op = 0;
    if((pos = equation.find('+')) != string::npos){
        op = '+';
    }
    else if((pos = equation.find('-')) != string::npos){
        op = '-';
    }
    else{
        cout<<"運算式不存在"<<endl;
        return 0;
    }

    int a = stoi(equation.substr(0, pos));
    int b = stoi(equation.substr(pos+1));

    int result;
    if(isABS){
        result = abc.absDiff(a, b);
    }
    else if(op == '+'){
        result =  abc.add(a, b);
    }
    else{
        result = abc.subtract(a, b);
    }

    cout<<"結果為: "<< result << endl;
    return 0;
}
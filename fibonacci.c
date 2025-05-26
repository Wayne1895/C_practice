#include<stdio.h>
int fib(int n){
    if(n==0 || n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    printf("fib(10)=%d\n",fib(10));
    printf("fib(99)=%d\n",fib(99));
    printf("fib(51)=fib(50)+fib(49)=%d+%d=%d\n",fib(50),fib(49),fib(51));
}
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    double *p = (double *)malloc(sizeof(double));  // 分配記憶體
    if (p == NULL) {  // 檢查 malloc 是否成功
        cout << "記憶體分配失敗" << endl;
        return 1;
    }

    cout << "輸入一個數字: ";
    cin >> *p;

    // 修正 printf 格式：%f 用來印 double，%p 用來印指標
    printf("值為 %f，地址為 %p\n", *p, (void *)p);

    free(p);  // 釋放正確的指標，不要寫成 free(*p)
    
    return 0;
}
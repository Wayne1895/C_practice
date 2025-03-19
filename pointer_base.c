#include <stdio.h>
#include <stdlib.h>  // 這裡是 stdlib.h，不是 stdib.h

int main() {
    int a = 0;
    int *p = &a;

    // 使用 %p 格式化指標
    printf("指標 p 的值 (a 的位址): %p\n", (void *)p);  

    *p = 100;  // 修改 a 的值
    printf("變數 a 的新值: %d\n", a);

    return 0;
}
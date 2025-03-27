#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[50];
    int age;
    float gpa;
};

int main(){
    printf("輸入學生個數\n");
    int n;
    scanf("%d", &n);
    if(n <= 0){
        printf("學生個數應為正整數\n");
        return 0;
    }
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    if(students == NULL){
        printf("記憶體分配失敗\n");
        return 0;
    }
    printf("輸入%d個學生的資料:\n依序為姓名、年紀、GPA分數:\n",n);
    for(int i = 0; i < n;i++){
        scanf("%s %d %f",students[i].name, &students[i].age, &students[i].gpa);
    }
    for(int i = 0;i < n;i++){
        printf("student%d - 姓名:%s、年紀:%d、GPA:%.1f\n",i+1 , students[i].name, students[i].age, students[i].gpa);
    }
    free(students);
    return 0;

}
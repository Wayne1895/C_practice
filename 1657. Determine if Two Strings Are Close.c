#include <stdbool.h>
int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}
bool closeStrings(char* word1, char* word2) {
    int count1[26]={0};
    int count2[26]={0};
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if(len1 != len2){
        return false;
    }
    for(int i=0;i<len1;i++){
        count1[word1[i] - 'a']++;
    }
    for(int i=0;i<len2;i++){
        count2[word2[i] - 'a']++;
    }
    for(int i =0;i<26;i++){
        if((count1[i]==0 && count2[i]!=0) || (count2[i]==0 && count1[i]!=0)){
            return false;
        }
    }
    qsort(count1, 26, sizeof(count1[0]), cmp);
    qsort(count2, 26, sizeof(count2[0]), cmp);
    for(int i = 0;i<26;i++){
        if(count1[i] != count2[i]){
            return false;
        }
   
    }
    return true;
}
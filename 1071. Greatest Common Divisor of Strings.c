#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b){
    return b==0?a:gcd(b, a % b);
}
char* gcdOfStrings(char* str1, char* str2) {
    char* str1_front = (char*)malloc(strlen(str1)+strlen(str2)+1);
    char* str2_front = (char*)malloc(strlen(str1)+strlen(str2)+1);

    strcpy(str1_front, str1);
    strcat(str1_front, str2);

    str2_front[0] = '\0';
    strcat(str2_front, str2);
    strcat(str2_front, str1);

    if (strcmp(str1_front, str2_front) != 0) {
        free(str1_front);
        free(str2_front);
        return "";
    }
    free(str1_front);
    free(str2_front);

    int gcdlen = gcd(strlen(str1), strlen(str2));
    char* result = (char*)malloc((sizeof(char)*(gcdlen+1)));
    strncpy(result, str2, gcdlen);
    result[gcdlen] = '\0';
    
    return result;

}
char* decodeString(char* s) {
    int num_stack[30];
    int num_top = 0, string_top=0;
    char* string_stack[30];
    int len = strlen(s);
    char* curr = (char*)calloc(10000, sizeof(char));


    for(int i=0;i<len;i++){
        if(isdigit(s[i])){
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            num_stack[num_top++]=num;
            i--;
        }
        else if(s[i] == '['){
            string_stack[string_top++] = curr;
            curr = (char*)calloc(10000, sizeof(char));
        }
        else if(s[i]== ']'){
            int repeat = num_stack[--num_top];
            char* prev = string_stack[--string_top];
            char* temp = (char*)calloc(10000, sizeof(char));
            for (int j = 0; j < repeat; j++) {
                strcat(temp, curr);
            }
            strcat(prev, temp);
            free(curr);
            free(temp);
            curr = prev;
        }
        else{
            char temp[] = {s[i], '\0'};
            strcat(curr, temp);
        }
    } 
    return  curr;
}
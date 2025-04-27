void reverse(char* begin, char* end){
    while(begin < end){
    char temp = *begin;
    *begin = *end;
    *end = temp;
    begin++;
    end--;
    }
}

char* reverseWords(char* s) {
    while(*s == ' '){
        s++;
    }
    int len = strlen(s);
    while(len>0 && s[len-1] == ' '){
        s[--len] = '\0';
    }
    char* wordbegin = s;
    char* position = s;
    
    while(*position){
        position++;
        if(*position == ' ' || *position == '\0'){
            reverse(wordbegin, position-1);
            wordbegin = position+1;
        }
    }
    reverse(s, s+len-1);
    char* kill_space = s;
    position = s;

    while(*position){
        if(*position != ' ' || (*(position+1) != ' ' && *(position+1) != '\0')){
            *kill_space = *position;
            kill_space++; 
        }
        position++;
    }
    *kill_space = '\0';
    return s;
    
}
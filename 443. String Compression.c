int compress(char* chars, int charsSize) {

    int i = 0, index = 0;

    while(i < charsSize){
        char temp = chars[i];
        int count = 0;
        while(i < charsSize && chars[i]==temp){
            count++;
            i++;
        }
        chars[index++] = temp;
        if(count > 1){
            char buffer[5];
            sprintf(buffer,"%d", count);
            for(int j= 0;buffer[j] != '\0';j++){
                chars[index++] = buffer[j];
            }
        }        
    }
    return index;
}
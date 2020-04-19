
void reverseString(char* s, int sSize){
    char tmp;
    int i = 0;
    for (i = 0; i < sSize / 2; i++) {
        tmp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = tmp;
    }
}


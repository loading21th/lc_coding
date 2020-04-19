// Source:  https://leetcode-cn.com/problems/add-strings/


void reverseString(char* s, int sSize){
    char tmp;
    int i = 0;
    for (i = 0; i < sSize / 2; i++) {
        tmp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = tmp;
    }
}


char * addStrings(char * num1, char * num2) {
    int i = 0, n1 = 0, n2 = 0, n3 = 0;
    char *p1 = num1, *p2 = num2;
    int resLen = strlen(num1) > strlen(num2) ? strlen(num1) : strlen(num2);
    char *resStr = malloc(resLen + 2);
    if (NULL == resStr)
        return NULL;
    memset(resStr, 0, resLen + 2);

    if (strlen(num2) > strlen(num1)) {
        p1 = num2;
        p2 = num1;
    }

    for (i = 0; i < strlen(p1); i++) {
        n1 = p1[strlen(p1) - i - 1] - 48;
        if (strlen(p2) >= i + 1) {
            n2 = p2[strlen(p2) - i - 1] - 48;
        } else {
            n2 = 0;
        }
        if (n1 + n2 + n3 > 9) {
            resStr[i] = (n1 + n2 + n3) % 10 + 48;
            n3 = (n1 + n2 + n3) / 10;
        } else {
            resStr[i] = (n1 + n2 + n3) % 10 + 48;
            n3 = 0;
        }
    }
    if (n3 > 0) {
        resStr[i] = n3 + 48;
    }
    reverseString(resStr, strlen(resStr));
    return resStr;
}


// Source: https://leetcode-cn.com/problems/valid-anagram/

bool isAnagram(char * s, char * t){
    char buf[26] = {};
    int i = 0, len = 0;

    if (strlen(s) != strlen(t))
        return false;

    for (i = 0; s[i] != '\0'; i++)
        buf[s[i] - 'a']++;
    for (i = 0; t[i] != '\0'; i++)
        buf[t[i] - 'a']--;

    for (i = 0; i < 26; i++) {
        if (buf[i] != 0)
            return false;
    }
    return true;
}


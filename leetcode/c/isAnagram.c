class Solution {
public:
    bool isAnagram(string s, string t) {
        char tmp[256]= {0};
        for (int i =0;i <s.length();i++){
            tmp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            tmp[t[i]]--;
        }
        for(int i=0;i<256;i++){
            if(0 != tmp[i]) return false;
        }
        return true;
    }
};

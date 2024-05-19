class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0;i<haystack.size();++i){
            int j;
            for(j = 0; j<needle.size();++j){
                if(needle[j] != haystack[i + j]) break;
            }
            if(j == needle.size()) return i;
        }
        return -1;
    }
};
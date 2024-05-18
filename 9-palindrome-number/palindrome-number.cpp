class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        for(int x = 0; x <= s.size()/2; x++){
            if(s[x] != s[s.size() - x -1]) return false;
        }
        return true;
    }
};
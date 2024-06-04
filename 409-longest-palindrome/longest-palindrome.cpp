class Solution {
public:
    int longestPalindrome(string s) {
        // pairs can be added to left and right of center, center can be one or two elements
        unordered_map<char, int> letters;
        int odd_elements = 0;
        
        for(char letter:s){
            ++letters[letter];
            if (letters[letter] % 2 == 1) odd_elements++;
            else odd_elements--;
        }
        if(odd_elements < 2) return s.size();
        return s.size() - odd_elements + 1;
    }
};
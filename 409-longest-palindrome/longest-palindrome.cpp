class Solution {
public:
    int longestPalindrome(string s) {
        // pairs can be added to left and right of center, center can be one or two elements
        set<char> letters;
        int amount_pairs = 0;
        
        for(char letter:s){
             if (letters.find(letter) == letters.end())
             {
                 letters.insert(letter);
                 continue;
             }
            letters.erase(letter);
            ++amount_pairs;
        }
        
        if(s.size() == 2 * amount_pairs) return s.size();
        return 2*amount_pairs + 1;
    }
};
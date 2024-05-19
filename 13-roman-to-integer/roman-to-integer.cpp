class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int> my_map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int integer = 0;
        int maxInt = 0;
        for(int i = s.size() - 1; i >= 0; --i){
            char digit = s[i];
            int numDigit = my_map[digit];
            if(numDigit < maxInt){
                integer -= numDigit;
                continue;
            }
            integer += numDigit;
            maxInt = max(maxInt, numDigit);
        }
        return integer;
    }
};
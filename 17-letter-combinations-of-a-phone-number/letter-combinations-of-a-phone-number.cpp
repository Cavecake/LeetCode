class Solution {
public:
    string digitToStr(char digit){
        if (digit == '2') return "abc";
        else if (digit == '3') return "def";
        else if (digit == '4') return "ghi";
        else if (digit == '5') return "jkl";
        else if (digit == '6') return "mno";
        else if (digit == '7') return "pqrs";
        else if (digit == '8') return "tuv";
        else if (digit == '9') return "wxyz";
        else return "";
    }
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        int index = 0;
        string combination = string(digits.size(),'1');
        while(index < digits.size()){
            // Backtracing
            if(combination[index]==digitToStr(digits[index]).back()){
                // Limit of current depth
                if(index == 0) break;
                combination[index] = '1';
                --index;
                continue;
            }
            // Get next string
            string chars = digitToStr(digits[index]);
            combination[index] = chars[chars.find(combination[index]) + 1];
            cout << combination << endl;
            
            if(index == digits.size() - 1){
                combinations.push_back(combination);
                continue;
            }
            // Move index back down
            ++index;
        }
        return combinations;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        bool digit = false;;
        bool negative = false;
        bool positive = false;
        long ans = 0;
        map<char,int> conversionTable = {
            {'0', 0},
            {'1', 1},
            {'2', 2},
            {'3', 3},
            {'4', 4},
            {'5', 5},
            {'6', 6},
            {'7', 7},
            {'8', 8},
            {'9', 9}
        };
        for(char elem: s){
            //cout << elem;
            //cout << " " << (!digit && elem == ' ');
            //cout << " " << (!digit && !positive && elem == '-');
            //cout << " " << (!digit && !negative && elem == '+');
            //cout << " " << conversionTable.count(elem);


            if(!(digit || negative || positive) && elem == ' ') continue;
            else if(!digit && !negative && !positive && elem == '-') negative = true;
            else if(!digit && !negative && !positive && elem == '+') positive = true;
            else if(conversionTable.count(elem)) {
                ans = 10*ans + conversionTable[elem];
                if(ans > INT32_MAX || ans < INT32_MIN){

                    ans = negative ? -ans : ans;
                    ans = ans > INT32_MAX ? INT32_MAX : INT32_MIN;

                    return ans;
                }
                digit = true;
            }
            else return negative ? -ans : ans;
        }
        ans = negative ? -ans : ans;
        ans = ans < INT32_MAX ? ans : INT32_MAX;
        ans = ans > INT32_MIN ? ans : INT32_MIN;

        return ans;
    }
};
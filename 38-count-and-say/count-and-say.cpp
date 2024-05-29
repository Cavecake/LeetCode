class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string lastString = countAndSay(n - 1);
        string ans = "";
        char lastChar = lastString[0];
        int amount = 0;
        for(char elem: lastString){

            if(elem == lastChar){
                ++amount;
                continue;
            }
            ans += to_string(amount) + lastChar;
            amount = 1;
            lastChar = elem;
        }

        if(amount != 0){
            ans += to_string(amount) + lastChar;
            amount = 0;
        }
        return ans;
    }
};
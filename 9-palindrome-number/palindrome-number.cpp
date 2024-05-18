class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x / 10 == 0) return true;

        int y = 0;

        while(x>=y){
            
            y = 10 *y + x % 10;
            x /= 10;

            cout << x << " " << y << endl;

            if(y == 0) return false;
            if(y == x) return true;
            if(y == x/10 && x/10 != 0) return true;
        }
        return false;
    }
};
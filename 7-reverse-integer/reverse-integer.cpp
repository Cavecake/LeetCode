class Solution {
public:
    int reverse(int x) {
        int maxNum[] = {2,1,4,7,4,8,3,6,4,6};
        bool checkDigits = x > 999999999 or x < -999999999;
        int index = 0;
        int result = 0;
        while(x != 0){
            if(checkDigits){
                cout << maxNum[index] << " < " << x % 10 << " < " << -maxNum[index] << endl;
                if(maxNum[index] < x % 10 || x%10 < -maxNum[index]) return 0;
                if(x%10 < 0 && x%10 > -maxNum[index]) checkDigits = false;
                if(x%10 > 0 && x%10 < maxNum[index]) checkDigits = false;

            }
            
            result = 10 * result +  x % 10;
            x = (int) x / 10;
            index++;
        }
        return result;
    }
};
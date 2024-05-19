class Solution {
public:
    string intToRoman(int num) {
        string RomanNumber = "";
        RomanNumber.insert(0,(int) num/1000,'M');
        num = num % 1000;
        string Symbols = "MDCLXVI";
        int index = 1;
        int digit = 2;
        while(num != 0){
            int digit = num / pow(10,(2 - index/2));
            if(digit == 4 || digit == 9) RomanNumber += Symbols[index + 1];
            if (digit >= 4 && digit < 9) RomanNumber += Symbols[index];
            if(digit == 9) RomanNumber += Symbols[index - 1];
            if(digit % 5 < 4) RomanNumber.insert(RomanNumber.end(), (int)digit%5, Symbols[index + 1]);

            num = num % (int) pow(10,(2 - index/2));
            index += 2;
        }
        return RomanNumber;
    }
};
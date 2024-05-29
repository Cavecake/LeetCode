class Solution {
public:
    int numSteps(string s) {
        // Add to left, carry
        // divide by two remove right;
        int steps = 0;
        while(s != "1"){
            ++steps;
            //cout << s << endl;
            if(s[s.size() - 1] == '0'){
                s.pop_back();
            }
            else{
                int index = s.size() - 1;
                while(index >= 0){
                    if(s[index] == '0'){
                        s[index] = 1;
                        break;
                    }
                    s[index] = '0';
                    --index;
                }
                if(index == -1) s = "1" + s;
            }
        }
        return steps;
    }
};
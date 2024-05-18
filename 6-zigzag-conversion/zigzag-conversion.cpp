class Solution {
public:
    string convert(string s, int numRows) {
        string output;
        for(int row = 0; row < numRows; row++){
            int index = row;
            while(index<s.size()){
                output += s[index];
                int nextIndex = index + numRows + max(numRows - 2, 0);
                int ziczacIndex = index + (numRows - row - 1) * 2;
                cout << ziczacIndex << " " << nextIndex << " " << index << endl;
                if(ziczacIndex != index && ziczacIndex != nextIndex && ziczacIndex < s.size()){
                    output += s[ziczacIndex];
                }
                index = nextIndex;
            }
        }
        return output;
    }
};
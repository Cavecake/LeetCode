class Solution {
public:
    bool isValid(string s) {
        stack<char> characters;
        //characters.push(')');
        for(char elem: s){
            if(elem == '(') characters.push(')');
            else if(elem == '[') characters.push(']');
            else if(elem == '{') characters.push('}');
            else if(characters.empty()) return false;
            else if(elem != characters.top()) return false;
            else characters.pop();
        }
        return characters.empty();
    }
};
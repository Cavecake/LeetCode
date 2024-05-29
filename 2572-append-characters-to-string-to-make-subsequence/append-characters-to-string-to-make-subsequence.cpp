class Solution {
public:
    int appendCharacters(string s, string t) {
        int index_t = 0;
        for(char character: s){
            if(character == t[index_t]) ++index_t;
            if(index_t == t.size()) return 0;
        }
        return t.size() - index_t;
    }
};
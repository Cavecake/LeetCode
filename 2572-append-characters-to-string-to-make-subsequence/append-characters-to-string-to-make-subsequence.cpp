class Solution {
public:
    int appendCharacters(string s, string t) {
        int index_t = 0;
        int size_t = t.size();
        int size_s = s.size();
        for(int i = 0; i < size_s; ++i){
            if(s[i] == t[index_t]) ++index_t;
            if(index_t == size_t) return 0;
        }
        return t.size() - index_t;
    }
};
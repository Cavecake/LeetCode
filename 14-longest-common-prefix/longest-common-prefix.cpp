class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int i =0;i < strs.size();++i){
            if(i == 0) {prefix = strs[i]; continue;}
            for(int j=0; j < min(strs[i].size(),prefix.size());++j){
                if(prefix[j] == strs[i][j]) continue;
                prefix = prefix.substr(0,j);
            }
            if(prefix.size() > strs[i].size()) {
                prefix = prefix.substr(0,strs[i].size());
            }
        }
        return prefix;
    }
};
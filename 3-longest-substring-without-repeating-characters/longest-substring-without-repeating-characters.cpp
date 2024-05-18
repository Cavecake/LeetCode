class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int startPoint = 0;
        int endPoint = 0;
        // Could also use an int with each bit representing a letter
        std::string characters = "";
        
        // Move until repeating
        // Always set maxLength
        // Set start to next
        while (endPoint < s.size()){
            if(characters.find(s[endPoint])<characters.length()){
                // Update maxLength
                int curLength = endPoint - startPoint;
                if(curLength>maxLength) maxLength = curLength;

                // Move start Point until every char occurs only once
                while(s[startPoint] != s[endPoint]){
                    startPoint++;
                }
                startPoint++;
                characters = "";
                for(int i=startPoint;i<=endPoint;i++){
                    characters += s[i];
                }
            }
            else{
                characters += s[endPoint];
            }
            endPoint++;
        }
        int curLength = endPoint - startPoint;
        if(curLength>maxLength) maxLength = curLength;

        return maxLength;
    }
};
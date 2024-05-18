class Solution {
public:
    int LevenshteinDistanceRecursive(string word1, string word2){
        if(word1 == "") return word2.size();
        if(word2 == "") return word1.size();
        string tailA = word1.substr(1, word1.size() - 1);
        string tailB = word2.substr(1, word2.size() - 1);
        if(word1[0] == word2[0]) return LevenshteinDistanceRecursive(tailA, tailB);

        // INSERT
        int insertCost = LevenshteinDistanceRecursive(tailA, word2);
        // Remove
        int RemoveCost = LevenshteinDistanceRecursive(word1, tailB);
        // Change
        int ExchangeCost = LevenshteinDistanceRecursive(tailA, tailB);
        return 1 + min(insertCost, min(RemoveCost, ExchangeCost));

    }

    int LevenshteinDistanceWithMemory(string word1, string word2){
        if(word1 == "") return word2.size();
        if(word2 == "") return word1.size();

        vector<vector<int>> dist(word1.size() + 1,vector<int>(word2.size() + 1));
        for(int i = 0; i <= word1.size(); ++i){
            dist[i][0] = i;
        }
        for(int i = 0; i <= word2.size(); ++i){
            dist[0][i] = i;
        }
        for(int i = 1; i <= word1.size(); ++i){
            for(int j = 1; j <= word2.size();++j){
                if(word1[i -1] == word2[j - 1]) dist[i][j] = dist[i-1][j-1];
                else{
                    int insertCost = 1 + dist[i-1][j];
                    int removalCost = 1 + dist[i][j - 1];
                    int exchangeCost = 1 + dist[i-1][j-1];
                    dist[i][j] = min(insertCost, min(removalCost, exchangeCost));
                }
            }
        }
        return dist[word1.size()][word2.size()];
    }

    int minDistance(string word1, string word2) {
        return LevenshteinDistanceWithMemory(word1, word2);
    }
};
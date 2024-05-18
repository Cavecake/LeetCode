class Solution {
public:
    int uniquePaths(int m, int n) {
        // This is n over/choose k with n == m + n and k = n
        vector<vector<int>> MEM(m,vector<int>(n, 1));
        for(int x = 1; x < m; ++x){
            for(int y = 1; y < n; ++y){
                MEM[x][y] = MEM[x-1][y] + MEM[x][y-1];
            }
        }
        return MEM[m - 1][n - 1];
    }
};
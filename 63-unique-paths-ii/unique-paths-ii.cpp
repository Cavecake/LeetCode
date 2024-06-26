class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> grid(m,vector<int>(n));
        for(int i=0; i <m; ++i){
            for(int j = 0; j <n; ++j){
                if (obstacleGrid[i][j] == 1) grid[i][j] = 0;
                else if (i == 0 && j == 0) grid[i][j] = 1;
                else if (i == 0) grid[i][j] = grid[i][j - 1];
                else if (j == 0) grid[i][j] = grid[i - 1][j];
                else grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[m - 1][n - 1];
    }
};
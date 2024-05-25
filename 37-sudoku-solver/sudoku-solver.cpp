class Solution {
public:
    bool validMove(vector<vector<char>>& board, char inserValue, int index){
        int insertX = index % 9;
        int insertY = index / 9;
        int boxX = (insertX / 3) * 3;
        int boxY = (insertY / 3) * 3;
        

        for(int i = 0;i<9;++i){
            if(board[i][insertX] == inserValue) return false;
            if(board[insertY][i] == inserValue) return false;
            if(board[boxY + i/3][boxX + i%3] == inserValue) return false;
        }
        return true;
    }
    bool backtracking(vector<vector<char>>& board, int index, vector<bool> given){
        string numbers = "123456789";
        if(index == 81) return true;
        if(given[index]) return backtracking(board,index + 1,given);
        // Check all values
        for(int i = 0; i< 9; ++i){
            if(validMove(board,numbers[i],index)){
                //cout << numbers[i] << " at " << index%9  + 1<< " " << index/9 + 1<< " is valid" << endl;
                board[index / 9][index % 9] = numbers[i];
                if(backtracking(board,index + 1,given)) return true;
            }
        }
        board[index / 9][index % 9] = '.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<bool> given;
        for(int i = 0; i<9;++i){
            for(int j = 0; j<9;++j){
                given.push_back(board[i][j] != '.');
            }
        }
        backtracking(board,0,given);
    }
};
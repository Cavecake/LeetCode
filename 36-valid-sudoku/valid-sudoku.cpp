class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> rows;
        vector<vector<char>> columns;
        vector<vector<char>> box;
        for(int x = 0; x < 9; ++x){
            rows.push_back({});
            columns.push_back({});
            box.push_back({});
        }
        for(int x = 0; x < 9; ++x){
            for(int y = 0; y < 9; ++y){
                int boxIndex = (x/3) + (y/3) * 3;
                char value = board[x][y];
                if(value == '.') continue;
                //cout << x << " " << y << " " << boxIndex << endl;
                if(box[boxIndex].size() != 0 && find(box[boxIndex].begin(), box[boxIndex].end(),value) != box[boxIndex].end()) return false;
                if(rows[x].size() != 0 && find(rows[x].begin(),rows[x].end(),value) != rows[x].end()) return false;
                if(columns[y].size() != 0 && find(columns[y].begin(),columns[y].end(),value) !=  columns[y].end()) return false;
                rows[x].push_back(value);
                columns[y].push_back(value);
                box[boxIndex].push_back(value);

            }
        }
        return true;
    }
};
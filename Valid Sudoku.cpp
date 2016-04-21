    /*
Determine if a Sudoku is valid
*/ 
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > rowFlag(9, vector<bool>(9, false));
        vector<vector<bool> > colFlag(9, vector<bool>(9, false));
        vector<vector<bool> > cellFlag(9, vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int c = board[i][j] - '1';
                    if (rowFlag[i][c] || colFlag[j][c] || cellFlag[3 * (i / 3) + j / 3][c]) return false;
                    rowFlag[i][c] = true;
                    colFlag[j][c] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};

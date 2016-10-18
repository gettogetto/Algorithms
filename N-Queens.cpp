class Solution {
public:
bool ok(vector<int> &col, int c, int idx) {
// Validates last queen with all previous queens. 
    for (int i = 0; i < idx; i++)
            if (col[i] == c || abs(col[i] - c) == abs(i - idx)) 
                return false; // Clash!
    return true;
}
vector<vector<string> > solveNQueens(int n) {
    vector<int> col(n, 0);
    vector<vector<string> > ans;
    int row = 0;

    while (1) {
        if (row == n) {
            // Generate string for this solution.
            string str(n,'.');
            vector<string> t(n, str);
            for (int i = 0; i < n; i++) t[col[i]][i] = 'Q';
            ans.push_back(t);

            col[--row]++; // go back to previous row and increment that queen by 1 column.
        }
        else if (col[row] == n) {
            col[row] = 0;       // Reset this queen to column 0.
            if (row == 0) break; // all cases checked! :)
            col[--row]++;           // go back to previous row and increment that queen by 1 column.
        }
        else if (!ok(col, col[row], row)) {
            col[row]++; // problem at this column, so go to next column.
        }
        else row++;   // everything's perfect, lets go to queen in next row.
    }
    return ans;
} 
};

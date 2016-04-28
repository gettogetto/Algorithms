/*
Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ¡Ü row2 and col1 ¡Ü col2.
*/
class NumMatrix {
private:
    vector<vector<int>>v;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int rows=matrix.size();
        if(rows==0) return ;
        int cols=matrix[0].size();
        if(cols==0) return ;
        v.resize(rows,vector<int>(cols));
        
        v[0][0]=matrix[0][0];
        for(int j=1;j<cols;j++) v[0][j]=v[0][j-1]+matrix[0][j];
        for(int i=1;i<rows;i++) v[i][0]=v[i-1][0]+matrix[i][0];
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                v[i][j]=matrix[i][j]+v[i][j-1]+v[i-1][j]-v[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1>0&&col1>0) return v[row2][col2]-v[row1-1][col2]-v[row2][col1-1]+v[row1-1][col1-1];
        else if(row1>0) return v[row2][col2]-v[row1-1][col2];
        else if(col1>0) return v[row2][col2]-v[row2][col1-1];
        else return v[row2][col2]; 
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);

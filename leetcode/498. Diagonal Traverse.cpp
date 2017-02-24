/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
*/ 
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();if(row==0) return {};
        int col=matrix[0].size();if(col==0) return {};
        int time=row+col-1;
        vector<int> res;
        for(int i=1;i<=time;i++){
            if(i&1){//斜向上
                int tmp=i-1;
                int r,c;
                if(tmp<=row-1) r=tmp,c=0;
                else r=row-1,c=tmp-(row-1);
                while(r>=0&&c<=col-1){
                    res.push_back(matrix[r--][c++]);
                }
                
            }else{//斜向下
                int tmp=i-1;
                int r,c;
                if(tmp<=col-1) c=tmp,r=0;
                else r=tmp-(col-1),c=col-1;
                while(r<=row-1&&c>=0){
                    res.push_back(matrix[r++][c--]);
                }
            }
        }
        return res;
    }
};

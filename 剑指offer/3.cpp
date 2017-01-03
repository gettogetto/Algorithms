/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        if(n==0) return false;
        int start=0,end=m*n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[mid/n][mid%n]>target) end=mid-1;
            else if(matrix[mid/n][mid%n]<target) start=mid+1;
            else return true;
        }
        return false;
    }
};
/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if(row==0) return false;
        int col=matrix[0].size();
        
        int found=false;
        int r=0,c=col-1;
        while(r<row&&c>=0){
            if(matrix[r][c]>target){
                c--;
            }else if(matrix[r][c]<target){
                r++;
            }else{
                found=true;
                break;
            }
        }
        return found;
    }
};

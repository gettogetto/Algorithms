/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
class Solution {
public:
    bool col[10][10],row[10][10],f[10][10];
    bool flag = false;//标记是否得到合法解
    void solveSudoku(vector<vector<char>>& board) {
         memset(col,false,sizeof(col));
         memset(row,false,sizeof(row));
         memset(f,false,sizeof(f));
         for(int i = 0; i < 9;i++){
             for(int j = 0; j < 9;j++){
                 if(board[i][j] == '.')   continue;
                 int temp = 3*(i/3)+j/3;
                 int num = board[i][j]-'0';
                 col[j][num] = row[i][num] = f[temp][num] = true;
             }
         }
         dfs(board,0,0);
    }
    void dfs(vector<vector<char> >&board,int i,int j){
        if(flag) return;//找到解，返回 
        if(i>=9){//到达逾尾行，说明已找到解 
            flag=true;
            return ;
        }
        if(j==9) dfs(board,i+1,0);//到达某行的逾尾列，则继续下一行 
        if(j<=8){//未逾尾 
            if(board[i][j]!='.'){//不是空格，则下一个坐标 
                dfs(board,i,j+1);
            }else{
                for(int num=1;num<=9;num++){//对每个空格，从1-9逐一尝试 
                    
                    int temp = 3*(i/3)+j/3;
                    if(!col[j][num]&&!row[i][num]&&!f[temp][num]){
                        board[i][j]=num+'0';
                        col[j][num] = row[i][num] = f[temp][num] = true;  
                        dfs(board,i,j+1);
                        if(flag) return;//找到解则直接返回 
                        
                        board[i][j]='.';//未找到解，则回溯 
                        col[j][num] = row[i][num] = f[temp][num] = false; 
                    }
                }
            }
        }
    }

};

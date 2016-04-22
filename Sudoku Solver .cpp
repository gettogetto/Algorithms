/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
class Solution {
public:
    bool col[10][10],row[10][10],f[10][10];
    bool flag = false;//����Ƿ�õ��Ϸ���
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
        if(flag) return;//�ҵ��⣬���� 
        if(i>=9){//������β�У�˵�����ҵ��� 
            flag=true;
            return ;
        }
        if(j==9) dfs(board,i+1,0);//����ĳ�е���β�У��������һ�� 
        if(j<=8){//δ��β 
            if(board[i][j]!='.'){//���ǿո�����һ������ 
                dfs(board,i,j+1);
            }else{
                for(int num=1;num<=9;num++){//��ÿ���ո񣬴�1-9��һ���� 
                    
                    int temp = 3*(i/3)+j/3;
                    if(!col[j][num]&&!row[i][num]&&!f[temp][num]){
                        board[i][j]=num+'0';
                        col[j][num] = row[i][num] = f[temp][num] = true;  
                        dfs(board,i,j+1);
                        if(flag) return;//�ҵ�����ֱ�ӷ��� 
                        
                        board[i][j]='.';//δ�ҵ��⣬����� 
                        col[j][num] = row[i][num] = f[temp][num] = false; 
                    }
                }
            }
        }
    }

};

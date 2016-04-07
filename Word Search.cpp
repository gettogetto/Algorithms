/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
          int rows=board.size();
          if(rows==0) return false;
          int cols=board[0].size();   
          if(cols==0) return false;
          if(n>rows*cols) return false;
          
          for(int i=0;i<rows;i++){
              for(int j=0;j<cols;j++){
                  if( dfs(board,i,j,word,0) ) return true;
              }
          }
          return false;
    }
    bool dfs(vector<vector<char>>& board,int i,int j,string& word,int index){
        int rows=board.size();
        int cols=board[0].size();
        if(i<0||i>=rows||j<0||j>=cols||board[i][j]=='\0'||board[i][j]!=word[index]) return false;
        if(index==word.size()-1) return true;
        char t=board[i][j];
        board[i][j]='\0';
        if( dfs(board,i-1,j,word,index+1)||dfs(board,i+1,j,word,index+1)||dfs(board,i,j-1,word,index+1)||dfs(board,i,j+1,word,index+1))
            return true;
        board[i][j]=t;
        return false;
    }
};


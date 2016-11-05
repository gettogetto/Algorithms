/*
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int r=board.size();
        if(r ==0 ) return 0;
        int c = board[0].size();
        int cnt = 0;
        for(int i = 0;i<r;i++){
            for(int j = 0;j < c;j++){
                if(board[i][j]=='.') continue;
                if(i>0&&board[i-1][j]=='X') continue;
                if(j>0&&board[i][j-1]=='X') continue;
                cnt++;
            }
        }
        return cnt;
    }
};
//python
class Solution(object):
    def countBattleships(self, board):
        r = len(board)
        if r == 0:
            return 0
        c = len(board[0])
        cnt = 0
        for i in range(r):
            for j in range(c):
                if board[i][j]=='.':
                    continue
                if(i>0 and board[i-1][j]=='X'):
                    continue
                if(j>0 and board[i][j-1]=='X'):
                    continue
                cnt+=1
        return cnt

        

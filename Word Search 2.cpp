/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/
class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord=false;
        for (auto &a : child) a = NULL;
    }
    void insert(string s) {
        TrieNode *p = this;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    //do not need code below
    bool search(string key) {
        TrieNode *p = this;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        return p->isWord;
    }
    bool startsWith(string prefix) {
        TrieNode *p = this;
        for (auto &a : prefix) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        return true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int rows=board.size();
        int cols=board[0].size();
        TrieNode *trie=new TrieNode();
        for(int i=0;i<words.size();i++){
            trie->insert(words[i]);
        }
        string path;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                dfs(board,i,j,trie,path,res);
            }
        }
        return res;
    }
private:   
    void dfs(vector<vector<char>>& board,int i,int j,TrieNode* root,string path,vector<string>&res){
        int rows=board.size();
        int cols=board[0].size();
        if(root==nullptr||i<0||i>=rows||j<0||j>=cols||board[i][j]=='\0'){
            return ;
        }
        root=root->child[board[i][j]-'a'];
        if(root==nullptr) return;
        path.push_back(board[i][j]);
        if(root->isWord){
            res.push_back(path);
            root->isWord=false;//already add to res,so delete the word
        }
        char t=board[i][j];
        board[i][j]='\0';
        dfs(board,i-1,j,root,path,res);
        dfs(board,i+1,j,root,path,res);
        dfs(board,i,j-1,root,path,res);
        dfs(board,i,j+1,root,path,res);
        board[i][j]=t;
    }
};

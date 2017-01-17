//28附加习题2,八皇后 

#include<iostream>
#include<vector>
using namespace std;

bool isok(vector<int> &col){
	for(int row=0;row<8;row++){
		for(int r=0;r<row;r++){
			if(col[row]==col[r]||abs(row-r)==abs(col[row]-col[r])){
				return false;
			}
		}
	}
	return true;
}
void helper(vector<int> &col,int s){
	static int count=0;
	if(s==col.size()&&isok(col)){
		++count;cout<<count<<":";
		for(auto num:col) cout<<num<<" ";
		cout<<endl;
	}
	for(int i=s;i<col.size();i++){
		swap(col[s],col[i]);
		helper(col,s+1);
		swap(col[s],col[i]);//回溯，注意形参col如不是引用，则删掉此句 
	}
}
void permutation(vector<int> &col){
	helper(col,0);
}

int main(){
	vector<int> col={0,1,2,3,4,5,6,7};
	
	permutation(col);
} 


//附加n皇后求法 
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
            for (int i = 0; i < n; i++) t[i][col[i]] = 'Q';
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

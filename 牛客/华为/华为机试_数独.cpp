/*
数独是一个我们都非常熟悉的经典游戏，运用计算机我们可以很快地解开数独难题，现在有一些简单的数独题目，请编写一个程序求解。

输入描述:

输入9行，每行为空格隔开的9个数字，为0的地方就是需要填充的。


输出描述:

输出九行，每行九个空格隔开的数字，为解出的答案。
*/ 
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<vector<vector<int>>> ans;
bool validation(vector<vector<int>> data, pair<int,int> pos, int val){
    for(int i=0; i<9; i++){//行 
        if(i==pos.second)
            continue;
        if(data[pos.first][i]==val)
            return false;
    }
    for(int i=0; i<9; i++){//列 
        if(i==pos.first)
            continue;
        if(data[i][pos.second]==val)
            return false;
    }
    int x = pos.first / 3, y = pos.second / 3;
    for(int i=0; i<3; i++){//九宫 
        for(int j=0; j<3; j++){
            if(data[x*3+i][y*3+j]==val)
                return false;
        }
    }
    return true;
}

bool go(vector<vector<int>> &data, vector<pair<int,int>> zeros, int n){
    if(n==zeros.size()){
        ans.push_back(data);
        return true;
    }
    for(int i=1; i<10; i++){
        if(validation(data, zeros[n], i)){
            data[zeros[n].first][zeros[n].second] = i;
            go(data, zeros, n+1);
            data[zeros[n].first][zeros[n].second] = 0;
        }
    }
    return true;
     
}

void Print(vector<vector<int>> res){
    for(int i=0; i<9; i++){
        cout << res[i][0];
        for(int j=1; j<9; j++)
            cout << " " << res[i][j];
        cout << endl;
    }
}

int main(){
    vector<vector<int>> data;
    vector<pair<int,int>> zeros;
    vector<int> tmp;
    int x;
    for(int i=0; i<9; i++){
        tmp.clear();
        for(int j=0; j<9; j++){
            cin >> x;
            if(x==0)
                zeros.push_back(make_pair(i, j));
            tmp.push_back(x);
        }
        data.push_back(tmp);
    }
    go(data, zeros, 0);
    if(ans.size() > 0)
    Print(ans[0]);
    return 0;
}


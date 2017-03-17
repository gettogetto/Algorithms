/*
������һ�����Ƕ��ǳ���Ϥ�ľ�����Ϸ�����ü�������ǿ��Ժܿ�ؽ⿪�������⣬������һЩ�򵥵�������Ŀ�����дһ��������⡣

��������:

����9�У�ÿ��Ϊ�ո������9�����֣�Ϊ0�ĵط�������Ҫ���ġ�


�������:

������У�ÿ�оŸ��ո���������֣�Ϊ����Ĵ𰸡�
*/ 
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<vector<vector<int>>> ans;
bool validation(vector<vector<int>> data, pair<int,int> pos, int val){
    for(int i=0; i<9; i++){//�� 
        if(i==pos.second)
            continue;
        if(data[pos.first][i]==val)
            return false;
    }
    for(int i=0; i<9; i++){//�� 
        if(i==pos.first)
            continue;
        if(data[i][pos.second]==val)
            return false;
    }
    int x = pos.first / 3, y = pos.second / 3;
    for(int i=0; i<3; i++){//�Ź� 
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


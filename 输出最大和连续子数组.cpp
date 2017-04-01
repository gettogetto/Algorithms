#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &v){
    int n=v.size();
    int res_start=0;
    int res_end=0;
    int maxsum=0;
    int thissum=v[0];
    for(int i=1;i<n;i++){
        thissum+=v[i];
        if(thissum<v[i]){
            thissum=v[i];
            res_start=i;

        }else if(thissum>maxsum){
            res_end=i;

            maxsum=thissum;
        }
    }
    if(maxsum==0){
        int maxsum=v[0];
        res_start=res_end=0;
        for(int i=1;i<n;i++){
            if(v[i]>maxsum){
                res_start=res_end=i;
                maxsum=v[i];
            }
        }
    }
    for(int i=res_start;i<=res_end;i++) cout<<v[i]<<" ";
}

int main(){
    vector<int> v={-1,-2,-3,-6};//{1, -2, 3, 10, -4, 7, 2, -5};
    solve(v);
}

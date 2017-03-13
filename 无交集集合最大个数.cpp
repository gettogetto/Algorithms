#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

void count(vector<pair<int,int>> &v){
	int n=v.size();
	sort(v.begin(),v.end(),[](const pair<int,int>& p1,const pair<int,int>& p2){return p1.second<p2.second;}	);
	int lastval=v[0].second;
	vector<pair<int,int>> res(n);
	res[0]=v[0];
	int cnt=1;
	for(int i=1;i<n;i++){
		if(v[i].first<lastval) continue;
		else{
			res[cnt++]=v[i];
			lastval=v[i].second;
		}
	}
	for(int i=0;i<cnt;i++) cout<<"("<<res[i].first<<","<<res[i].second<<")"<<" ";
	
}
int main(){
	vector<pair<int,int> >v={{1,10},{2,5},{3,4},{1,4}};
	count(v);
}

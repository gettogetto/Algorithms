#include<iostream> 
#include<vector>
using namespace std;
bool isvalid(const vector<int>& v,int k){
	int n=v.size();
	for(int i=0;i<k;i++){
		if(v[i]==v[k]||abs(v[i]-v[k])==abs(i-k))
			return false;
	}
	return true;
}

void solve(vector<int>&v,int& cnt){
	int n=v.size();
	int k = 0;
	while(k>=0){
		if(k==n){
			cnt++;
			for(auto i:v) cout<<i;
			cout<<endl;
			//不能结束，返回上一行，继续求解其余合理结果 
			k--;
			v[k]++;
		}else if(v[k]==n){
			v[k]=0;
			k--;
			v[k]++;	
		}else if(!isvalid(v,k)){
			v[k]++;
		} else{
			k++;
		}
		
	}
}
int main(){
	vector<int> v(8,0);
	int cnt=0;
	solve(v,cnt);
	cout<<cnt;
}

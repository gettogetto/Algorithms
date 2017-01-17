#include<iostream>
#include<vector>
using namespace std;

bool checkmorethanhalf(const vector<int>& v,int num){
	int count=0;
	for(int i=0;i<v.size();i++){
		if(num==v[i]){
			count++;
		}
	}
	return count>=v.size()/2;
}
int morethanhalf(const vector<int>& v){
	int count=1;
	int res=v[0];
	for(int i=1;i<v.size();i++){
		if(count==0){
			res=v[i];
			count=1;
		}	
		if(v[i]==res) count++;
		else count--;
	}
	if(checkmorethanhalf(v,res)) return res;
	else return 0;
} 
int main(){
	vector<int> v={0,1,2,3,4,4,3,4,4,4};
	cout<<morethanhalf(v);
}

#include<iostream>
#include<vector>
using namespace std;

int maxSubArraySum(const vector<int>& v){
	int maxsum=INT_MIN,thissum=0;
	for(int i=0;i<v.size();i++){
		thissum+=v[i];
		if(thissum<0){
			thissum=0;
		} 
		if(thissum>maxsum){
			maxsum=thissum;
		}
	}
	return maxsum;
}
int main(){
	vector<int> v={1,-2,3,10,-4,7,2,-5};
	cout<<maxSubArraySum(v);
}

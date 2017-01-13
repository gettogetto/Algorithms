//判断是否为可能的出栈顺序 
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isPopOrder(const vector<int>& vpush,const vector<int>& vpop){
	stack<int> s;//辅助栈 
	int i=0,j=0;
	while(j<vpop.size()){
		while(s.empty()||s.top()!=vpop[j]){
			if(i==vpush.size()) break;
			s.push(vpush[i]);
			i++;
		}
		if(s.top()!=vpop[j]) break;
		s.pop();
		j++;
	}	
	return s.empty()&&j==vpop.size(); 

}
int main(){
	vector<int> nums{1,2,3,4,5};
	vector<int> order{4,3,5,2,1};
	cout<<isPopOrder(nums,order);
}

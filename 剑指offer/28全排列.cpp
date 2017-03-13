//�޷������ظ�Ԫ�� 
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void helper(string &str,int s){
	if(s==str.size()) cout<<str<<endl;
	for(int i=s;i<str.size();i++){
		swap(str[s],str[i]);
		helper(str,s+1);
		swap(str[s],str[i]);//���ݣ�ע���β�str�粻�����ã���ɾ���˾� 
	}
}
void permutation(string &str){
	helper(str,0);
}
////////////////////////////////////////////////
//�����ظ�Ԫ�� 
bool nextPermutation(vector<int> &num) {
	if (num.size() <= 1) return false;
    
	int i = (int)num.size() - 1;
	while (i > 0 && num[i] <= num[i-1])//�ҳ�����ĺ�׺ 
		--i;
	if (i == 0) {
		//reverse(num.begin(), num.end());
		return false;
	}
	
	--i;
	int j = (int)num.size() - 1;
	while (!(num[i] < num[j])) //�ҵ���һ����i����Ԫ�� 
		--j;
	
	swap(num[i], num[j]);//����λ�� 
	reverse(num.begin() + i + 1, num.end());//��ת����������׺ 
	return true;
}
int main(){
	string str;
	cin>>str;
	permutation(str);
////////////////////////
	vector<int> v={1,2,3};
	do{
		for(auto i:v) cout<<i<<" ";
		cout<<endl;
	} while(nextPermutation(v));
	
	
}

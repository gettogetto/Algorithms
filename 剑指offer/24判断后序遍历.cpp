#include<iostream>
#include<vector>
using namespace std;
bool judgePostOrder(vector<int>& nums){
	if(nums.empty()) return true;
	int rootval=nums.back();
	//���һ��Ԫ��Ϊ����ǰ���Ԫ�ط�Ϊ�����֣��������С�ڸ�ֵ��Ϊ��������ʣ���ұߵı�����ڸ�ֵ�������������������Ϊ���������Դ���ݹ���������Ԫ�� 
	int i=0;

	while(i<nums.size()-1&&nums[i]<rootval){
		i++;
	}
	int tmp=i;
	while(tmp<nums.size()-1){
		if(nums[tmp]<rootval) return false;//ʣ���ұߵı�����ڸ�ֵ��������� 
		tmp++;
	}
	vector<int> leftnums(nums.begin(),nums.begin()+i);
	vector<int> rightnums(nums.begin()+i,nums.end()-1);
	bool res1=judgePostOrder(leftnums);
	bool res2=judgePostOrder(rightnums);
	return res1&&res2;
}
int main(){
	vector<int> v{1,4,3,7,9,8,5};
	cout<<judgePostOrder(v)<<endl;
}
//��һ�������ж��Ƿ�Ϊһ��BST��ǰ�������ֻ��Ѹ�ֵ��Ϊ��һ��Ԫ�� 

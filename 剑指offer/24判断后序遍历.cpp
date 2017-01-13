#include<iostream>
#include<vector>
using namespace std;
bool judgePostOrder(vector<int>& nums){
	if(nums.empty()) return true;
	int rootval=nums.back();
	//最后一个元素为根，前面的元素分为两部分，左边所有小于根值的为左子树，剩下右边的必须大于根值，否则错误，若满足则作为右子树。以此类递归这两部分元素 
	int i=0;

	while(i<nums.size()-1&&nums[i]<rootval){
		i++;
	}
	int tmp=i;
	while(tmp<nums.size()-1){
		if(nums[tmp]<rootval) return false;//剩下右边的必须大于根值，否则错误， 
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
//举一反三：判断是否为一个BST的前序遍历，只需把根值改为第一个元素 

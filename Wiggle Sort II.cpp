#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
//O(nlgn)+o(n)
void wiggleSort(vector<int>&nums){
	int n=nums.size();
	vector<int>tmp=nums;
	sort(tmp.begin(),tmp.end());
	int left=(n+1)/2;
	int right=n;
	for(int i=0;i<n;i++){
		nums[i]=(i&1)?tmp[--right]:tmp[--left];
	}
	return;
}
//O(n)+O(1)
void wiggleSort2(vector<int>& nums) {
    int n = nums.size();

    // Find a median.
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // ÈýÏòÇÐ·Ö  O(n) time  O(1) space.
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}
int main(){
	vector<int>v{1,1,4,1,6,5};
	wiggleSort2(v);
	for(auto a:v) cout<<a<<" ";
}

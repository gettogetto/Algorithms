#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int solution(deque<int> a)
{
	int n=a.size();
	int l = 0, r = n - 1;
    int res = 0; 
    while(l < r){ 
        if (a[l] < a[r]){ 
            a[l+1] += a[l]; 
            ++l; ++res; 
        } else if(a[l] > a[r]){ 
            a[r-1] += a[r]; 
            --r; ++res; 
        }else{ 
            ++l, --r; 
        } 
    }
    return res;
}
int main(){
	int len;
	cin>>len;
	deque<int> nums(len);
	for(auto&i:nums) cin>>i;
	cout<<solution(nums)<<endl;

}

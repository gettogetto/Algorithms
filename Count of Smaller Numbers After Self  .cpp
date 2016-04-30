/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
*/

class Solution {
public:
	//findIndex() has been replaced by lower_bound()
	int findIndex(int toInsert,vector<int>&sorted){
        int n=sorted.size();
        int left=0,right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(toInsert>sorted[mid]){
                left=mid+1;
            }else{
            	right=mid-1;
			}
        }
        return left;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
        	auto it=lower_bound(sorted.begin(),sorted.end(),nums[i]);
        	res[i]=it-sorted.begin();
        	sorted.insert(it,nums[i]);
		}
		return res;
    }   
};


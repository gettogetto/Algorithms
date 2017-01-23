class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        int n=nums.size();
        if(n<=2) return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int left=i+1,right=n-1;
            int target=-nums[i];
            
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum<target) left++;
                else if(sum>target) right--;
                else{
                    vector<int> triplets(3);
                    triplets[0]=nums[i];triplets[1]=nums[left];triplets[2]=nums[right];
                    res.push_back(triplets);
                    while(left<right&&nums[left]==triplets[1]) left++;
                    while(left<right&&nums[right]==triplets[2]) right--;
                }
            }
            while(i<n-1&&nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};

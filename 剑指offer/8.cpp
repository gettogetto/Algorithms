/*Find Minimum in Rotated Sorted Array£¬not contain duplicated*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        while(left<right){
            if(nums[left]<nums[right]) return nums[left];
            int mid=left+(right-left)/2;
            if(nums[mid]>=nums[left]){
                left=mid+1;
            }
            else {
                right=mid;
            }
        }
        return nums[left];
    }
};
/*Find Minimum in Rotated Sorted Array£¬ contain duplicated*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]<nums[right]){
                right=mid;
            }else if(nums[mid]>nums[right]){
                left=mid+1;
            }else{
                right--;
            }
        }
        return nums[left];
    }
};



/* Search in Rotated Sorted Array ,not contain duplicated*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[left]){
                if(target>=nums[left]&&target<nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(target<=nums[right]&&target>nums[mid]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return nums[right]==target?right:-1;
    }
};

/* Search in Rotated Sorted Array , contain duplicated*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(target==nums[mid]) return true;
            if(nums[mid]<nums[right]){
                if(target<=nums[right]&&target>nums[mid]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else if(nums[mid]>nums[right]){
                if(target>=nums[left]&&target<nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                right--;
            }
        }
        return nums[left]==target?true:false;
    }
};

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		vector<int> res;
        if(array.size()<2) return res;
        int res1=array[0],res2=array[0];
        long long multi=LONG_LONG_MAX;
        int left=0,right=array.size()-1;
        while(left<right){
            int thissum=array[left]+array[right];
            if(thissum<sum) left++;
            else if(thissum>sum) right--;
            else{
                if(array[left]*array[right]<multi){
                	multi=array[left]*array[right];
                    res1=array[left];
                	res2=array[right];
                }
               // while(left<right&&array[left]==array[left+1]) left++;
               // while(left<right&&array[right]==array[right-1]) right--;
                right--;
    		}
        }
        if(res1+res2==sum){
        	res.push_back(res1);
        	res.push_back(res2);
        }
        return res;
    }
};

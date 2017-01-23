class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >res;
        int left=1,right=2;
        int thissum=left+right;
        
        while(left<right){
            thissum=(left+right)*(right-left+1)/2;
            if(thissum==sum){
				vector<int> v;
                for(int i=left;i<=right;i++) v.push_back(i);
                res.push_back(v);
                left++;
                right++;
            }else if(thissum<sum){
                right++;
            }else{
				left++;
            }
        }
        return res;
    }
};

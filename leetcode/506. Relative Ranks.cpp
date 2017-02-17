
/*
Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
*/

    #include<vector>
    #include<iostream>
    #include<algorithm>
    #include<queue>
    #include<string>
    #include<typeinfo>
    using namespace std;
    /*auto comp=[](int a,int b){return a<b;};
	struct cmp{
	  bool operator()(int a, int b){
	    return a<b;
	  }
	}; */
	vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        //priority_queue<int,vector<int>,decltype(comp) > pq(comp);
        //priority_queue<int,vector<int>,cmp > pq;
        //priority_queue<int,vector<int>,greater<int>> pq;
        priority_queue<int,vector<int>/*,less<int>*/> pq;
        for(auto i:nums) pq.push(i);
        int t=1;
        while(t<=nums.size()){
            int score=pq.top();
            pq.pop();
            for(int i=0;i<nums.size();i++){
                if(nums[i]==score) {
					res[i]=to_string(t);
	                if(t==1) res[i]="Gold Medal";
	                if(t==2) res[i]="Silver Medal";
	                if(t==3) res[i]="Bronze Medal";
            	}
            }
            t++;
            
        }
        return res;
    }
//·¨¶þ 
    vector<string> findRelativeRanks2(vector<int>& nums) {
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        vector<string> res(nums.size(),"");
        int count = 1;
        for(int i=0; i<nums.size();i++)
        {
            if(count==1) {res[pq.top().second] = "Gold Medal"; }
            else if(count==2) {res[pq.top().second] = "Silver Medal"; }
            else if(count==3) {res[pq.top().second] = "Bronze Medal"; }
            else {res[pq.top().second] = to_string(count); }
            pq.pop();
            count++;
        }
        return res;
    }

    int main(){
    	vector<string> res;
    	vector<int> nums={5, 4, 3, 2, 1};
    	res=findRelativeRanks(nums);
    	for(auto str:res) cout<<str<<endl;
	}

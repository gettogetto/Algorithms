/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string> > res;
        recurBacktracking(s,0,tmp,res);
        return res;
    }
    void recurBacktracking(const string& str,int start,vector<string>& tmp,vector<vector<string> >& res){
        if(start==str.size()) {
            res.push_back(tmp);
            return;
        }
        for(int i=start+1;i<=str.size();i++){
            string substring=str.substr(start,i-start);
            if(isPalindrome(str,start,i-1)) {
                tmp.push_back(substring);
                recurBacktracking(str,i,tmp,res);
                tmp.pop_back();
            }
                
        }
    }
    bool isPalindrome(const string& str,int left,int right){
        while(left<right){
            if(str[left]!=str[right]) return false;
            else left++,right--;
        }
        return true;
    }
};

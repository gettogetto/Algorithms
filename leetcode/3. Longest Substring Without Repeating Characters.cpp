/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. 
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            vector<int> map(128,0);
            int counter=0, begin=0, end=0, d=0; 
            while(end<s.size()){
                if(map[s[end++]]++>0) counter++; 
                while(counter>0) if(map[s[begin++]]-->1) counter--;
                d=max(d, end-begin); //while valid, update d
            }
            return d;
        }
};


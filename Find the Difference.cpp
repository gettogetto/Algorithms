/*
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        unordered_map<int,int>count;
        for(auto c:s) count[c]++;
        for(auto c:t){
            if(--count[c]<0) return c;
        }
        return 0;
    }
};

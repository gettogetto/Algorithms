#include<iostream>
#include<string>
#include<vector>
using namespace std;
int lengthOfLongestSubstring(string s) {
    vector<int> charIndex(256, -1);
    int longest = 0, m = 0;
    for (int i = 0; i < s.length(); i++) {
        m = max(charIndex[s[i]] + 1, m);
        charIndex[s[i]] = i;
        longest = max(longest, i - m + 1);
    }
    return longest;
}
int main(){
	string str;
	while(getline(cin,str)){
		cout<<lengthOfLongestSubstring(str)<<endl;
	}
}

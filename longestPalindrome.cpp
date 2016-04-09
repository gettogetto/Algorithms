/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include<iostream>
#include<string>
using namespace std;
string longestPalindrome(string s) {
    int len=s.size();
    if(len<=1) return s;
    int left=0,right=0,maxleft=0,maxlen=1;
    for(int start=0;len-start>maxlen/2;){
        left=right=start;
        while(right<len-1&&s[right]==s[right+1]) right++;
        start=right+1;
        while(left>0&&right<len-1&&s[left-1]==s[right+1]){
            left--;right++;
        }
        if(right-left+1>maxlen){
            maxlen=right-left+1;
            maxleft=left;
        }
    }
    return s.substr(maxleft,maxlen);
}
int main(){
	string str;
	while(cin>>str)
		cout<<longestPalindrome(str)<<endl;
}

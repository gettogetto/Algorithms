//Given a string S, find the longest palindromic substring in S. 
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
class Solution {
public:

string longestPalindrome(string str) {
    
    if(str.empty()) return "";
    int len=str.length();
    int min_start=0;//最长回文字串的起点
    int max_len=1;//最长回文字串的长度
    
    for(int i=0;i<len-1;){
        if(len-i<=max_len/2) break;//剩下的长度已经比当前最长回文字串的一半长度还小，已经不用算了
        int left=i;//回文字串的起点
        while(i<len-1&&str[i]==str[i+1]) i++;//跳过重复字符
        int right=i;//回文字串的终点
        i++;//准备下次循环
        
        while(left>0&&right<len-1&&str[left-1]==str[right+1]){//往两边扩展
            left--;
            right++;
        }
        
        if(max_len<right-left+1){
            min_start=left;
            max_len=right-left+1;
        }
    }
    return str.substr(min_start,max_len);
}

};


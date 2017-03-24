
/*

题目描述
A string s is LUCKY if and only if the number of different characters in s is a fibonacci number. Given a string consisting of only lower case letters , output all its lucky non-empty substrings in lexicographical order. Same substrings should be printed once. 
输入描述:
a string consisting no more than 100 lower case letters.


输出描述:
output the lucky substrings in lexicographical order.one per line. Same substrings should be printed once.

输入例子:
aabcd

输出例子:
a 
aa 
aab 
aabc 
ab 
abc 
b 
bc 
bcd 
c 
cd 
d
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

bool isFibonacci(int num){
    int a=0;
    int b=1;
    int c= a+b;
    while(c<num){
        a=b;
        b=c;
        c=a+b;
    }
    return c==num;
}

int countDiff(string& s){
    unordered_map<char,bool>um;
    int cnt=0;
    for(auto ch:s){
        if(!um[ch]){
            um[ch]=true;
            cnt++;
        }
    }
    return cnt;
}


int main(){
    string str;
    cin>>str;
    vector<string> res;
    int n=str.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string s=str.substr(i,j-i+1);
            if(isFibonacci(countDiff(s))){
                res.push_back(s);
            }
        }
    }
    sort(begin(res),end(res));
    res.erase(unique(begin(res),end(res)),res.end());//去重
    for(auto i:res) cout<<i<<endl;
    
    return 0;
}

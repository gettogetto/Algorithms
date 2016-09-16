#include<iostream>
#include<string>
using namespace std;

int solution(string str){
    int len=str.length();
    int min_start=0;
    int max_len=1;
    
    for(int i=0;i<len-1;){
        if(len-i<=max_len/2) break;
        int left=i;
        while(i<len-1&&str[i]==str[i+1]) i++;
        int right=i;
        i++;
        
        while(left>0&&right<len-1&&str[left-1]==str[right+1]){
            left--;
            right++;
        }
        
        if(max_len<right-left+1){
            min_start=left;
            max_len=right-left+1;
        }
    }
    return max_len;
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        cout<<solution(str)<<endl;
    }
    
    return 0;
}

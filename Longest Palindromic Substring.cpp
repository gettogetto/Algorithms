//Given a string S, find the longest palindromic substring in S. 
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
class Solution {
public:

string longestPalindrome(string str) {
    
    if(str.empty()) return "";
    int len=str.length();
    int min_start=0;//������ִ������
    int max_len=1;//������ִ��ĳ���
    
    for(int i=0;i<len-1;){
        if(len-i<=max_len/2) break;//ʣ�µĳ����Ѿ��ȵ�ǰ������ִ���һ�볤�Ȼ�С���Ѿ���������
        int left=i;//�����ִ������
        while(i<len-1&&str[i]==str[i+1]) i++;//�����ظ��ַ�
        int right=i;//�����ִ����յ�
        i++;//׼���´�ѭ��
        
        while(left>0&&right<len-1&&str[left-1]==str[right+1]){//��������չ
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


class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128,0);
        for(auto c:s) count[c]++;
        int res=0;
        int m=0;
        bool flag=0;
        for(auto n:count){
            if(n%2==0) res+=n;
            else res+=(n-1),flag=1;//��������Ԫ�ؿ۵�һ�������ż����
        }
        return flag?res+1:res;//�۹����ɼ�һ�����м�
    }
};

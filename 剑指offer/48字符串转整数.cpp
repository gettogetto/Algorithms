//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
// 数值为0或者字符串不是一个合法的数值则返回0 
class Solution {
public:
    int StrToInt(string str) {
        if(str.size()==0) return 0;
        int flag=1;
        int i=0;
        if(str[0]=='-') flag=-1,i++;
        if(str[0]=='+') flag=1,i++;
        int res=0;
        for(;i<str.size();i++){
            if(!isdigit(str[i])) return 0;
            res=10*res+(str[i]-'0');
        }
        return res*flag;
    }
};

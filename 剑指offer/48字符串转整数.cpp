//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯����
// ��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0 
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

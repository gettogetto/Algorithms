/*
�����������һ����λָ�����ѭ�����ƣ�ROL����
�����и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ����
����XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        reverse(str.begin(),str.begin()+n);
        reverse(str.begin()+n,str.end());
        reverse(str.begin(),str.end());
        return str;
    }
};

/*
ţţ�õ���һ���ر�ͼ��˳�Ųر�ͼ��ָʾ��ţţ������һ���ر��У��ر�������һ�����أ�����ÿ�λ���ʾ�����ַ��� s �� t�����ݹ��ϵĴ�˵��ţţ��Ҫÿ�ζ��ش� t �Ƿ��� s �������С�ע�⣬�����в�Ҫ����ԭ�ַ������������ģ����紮 abc�����������о��� {�մ�, a, b, c, ab, ac, bc, abc} 8 �֡� 
��������:
ÿ���������һ������������ÿ�����������������г��Ȳ����� 10 �Ĳ������ո�Ŀɼ� ASCII �ַ�����


�������:
���һ�� ��Yes�� ���� ��No�� ��ʾ�����

��������:
x.nowcoder.com
ooo

�������:
Yes
*/
#include<string>
#include<iostream>
using namespace std;
int main(){
    string str1,str2;
    cin>>str1>>str2;
    int i=0,j=0;
    while(i<str1.size()){
        if(str1[i]==str2[j]){
			i++;
            j++;
            
        }else{
            i++;
        }
    }
    if(j==str2.size()) cout<<"Yes";
    else cout<<"No";
}

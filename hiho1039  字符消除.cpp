/*
����
СHi�������һ���ַ�������Ϸ������һ��ֻ������д��ĸ"ABC"���ַ���s���������������½��еģ�



1)���s�������ȳ���1������ͬ��ĸ��ɵ��Ӵ�����ô��Щ�Ӵ��ᱻͬʱ���������µ��Ӵ�ƴ���µ��ַ���������"ABCCBCCCAA"��"CC","CCC"��"AA"�ᱻͬʱ����������"AB"��"B"ƴ���µ��ַ���"ABB"��

2)���������ᷴ��һ��һ�ֽ��У�ֱ���µ��ַ������������ڵ���ͬ�ַ�Ϊֹ�����硱ABCCBCCCAA������һ�������õ�"ABB"���پ���һ�������õ�"A"



��Ϸ�е�ÿһ��СHi�������һ���ַ���s����������ʼǰСHi�л�����s������λ��(��һ���ַ�֮ǰ�����һ���ַ�֮���Լ����������ַ�֮��)��������һ���ַ�('A','B'����'C')���õ��ַ���t��t����һϵ��������СHi�ĵ÷������������ַ���������



�����СHi����Ҫ��β����ַ������ܻ����ߵ÷֡�



����
�����һ����һ������T(1<=T<=100)������������ݵ�������

֮��T��ÿ��һ����'A''B''C'��ɵ��ַ���s�����Ȳ�����100��



���
����ÿһ��������ַ��������СHi����ܵõ��ķ�����



��ʾ
��һ�����ݣ���"ABCBCCCAA"�ĵ�2���ַ������'C'�õ�"ABCCBCCCAA"��������õ�"A"���ܹ�����9���ַ�(���������'C')��

�ڶ������ݣ�"AAA"����'A'�õ�"AAAA"��������õ�""���ܹ�����4���ַ���

���������ݣ������ǲ����ַ���õ�"AABC","ABBC"����"ABCC"���������2���ַ���



��������
3
ABCBCCCAA
AAA
ABC
�������
9
4
2
*/
#include<iostream>
#include<string>
using namespace std;
int deletetime(string str)//ɾ���ַ��ĸ��� 
{
	int len=str.size();

	str+='#';
	int newbegin=0;//��һ�������������ַ� 
	string newstr="";//ɾ����ʣ��ļӵ�newstr�� 
	for(int i=1;i<=len;i++){
		if(str[i]!=str[i-1]){
			if(i-1==newbegin) newstr+=str[i-1];
			newbegin=i;
		}
	}
	int len2=newstr.size();
	if(len-len2==0) return 0;
	return len-len2+deletetime(newstr);
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		
		int maxdeletetime=0,tmpdeletetime=0;
		for(int i=0;i<=s.size();i++){
			string tmp=s;
			tmp.insert(tmp.begin()+i,'A');//����tmp.insert(i,"A");
			tmpdeletetime=deletetime(tmp);
			maxdeletetime=max(tmpdeletetime,maxdeletetime);
			
			tmp=s;
			tmp.insert(tmp.begin()+i,'B');
			tmpdeletetime=deletetime(tmp);
			maxdeletetime=max(tmpdeletetime,maxdeletetime);
			
			tmp=s;
			tmp.insert(tmp.begin()+i,'C');
			tmpdeletetime=deletetime(tmp);
			maxdeletetime=max(tmpdeletetime,maxdeletetime);
			
			
			
		}
		cout<<maxdeletetime<<endl;
		
	}
}

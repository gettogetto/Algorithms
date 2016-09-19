/*
描述
小Hi最近在玩一个字符消除游戏。给定一个只包含大写字母"ABC"的字符串s，消除过程是如下进行的：



1)如果s包含长度超过1的由相同字母组成的子串，那么这些子串会被同时消除，余下的子串拼成新的字符串。例如"ABCCBCCCAA"中"CC","CCC"和"AA"会被同时消除，余下"AB"和"B"拼成新的字符串"ABB"。

2)上述消除会反复一轮一轮进行，直到新的字符串不包含相邻的相同字符为止。例如”ABCCBCCCAA”经过一轮消除得到"ABB"，再经过一轮消除得到"A"



游戏中的每一关小Hi都会面对一个字符串s。在消除开始前小Hi有机会在s中任意位置(第一个字符之前、最后一个字符之后以及相邻两个字符之间)插入任意一个字符('A','B'或者'C')，得到字符串t。t经过一系列消除后，小Hi的得分是消除掉的字符的总数。



请帮助小Hi计算要如何插入字符，才能获得最高得分。



输入
输入第一行是一个整数T(1<=T<=100)，代表测试数据的数量。

之后T行每行一个由'A''B''C'组成的字符串s，长度不超过100。



输出
对于每一行输入的字符串，输出小Hi最高能得到的分数。



提示
第一组数据：在"ABCBCCCAA"的第2个字符后插入'C'得到"ABCCBCCCAA"，消除后得到"A"，总共消除9个字符(包括插入的'C')。

第二组数据："AAA"插入'A'得到"AAAA"，消除后得到""，总共消除4个字符。

第三组数据：无论是插入字符后得到"AABC","ABBC"还是"ABCC"都最多消除2个字符。



样例输入
3
ABCBCCCAA
AAA
ABC
样例输出
9
4
2
*/
#include<iostream>
#include<string>
using namespace std;
int deletetime(string str)//删除字符的个数 
{
	int len=str.size();

	str+='#';
	int newbegin=0;//第一个不可消除的字符 
	string newstr="";//删除后剩余的加到newstr上 
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
			tmp.insert(tmp.begin()+i,'A');//或者tmp.insert(i,"A");
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

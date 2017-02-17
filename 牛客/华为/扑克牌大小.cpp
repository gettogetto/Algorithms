/*
题目描述

扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:) 
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER 
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.

输入描述:
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如4 4 4 4-joker JOKER。


输出描述:
输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。

输入例子:
4 4 4 4-joker JOKER

输出例子:
joker JOKER

分析：把输入分成两个字符串，由于扑克牌里的字符比较比较混乱，我直接把数据处理了一下存到了vector里，然后再分情况比较，如果有一方为大小王，那肯定是大小王大，如果有一方有炸弹，那就要分另一方是不是也是炸弹，是炸弹就要比较大小，不是的话肯定是炸弹大。剩余的情况只要比较vector中第一个数哪个比较大就可以了，当然前提是两者是可以比较的也就是vector的size相同。
*/
#include <iostream>  
#include <vector>  
#include <string>  
using namespace std;  
vector<int> helper(string s){  
    vector<int> v;  
    for(int i=0;i<s.size();i++){  
        if(s[i]=='1'){  
            v.push_back(10);  
            i++;  
        }   
        else if(s[i]=='J') v.push_back(11);  
        else if(s[i]=='Q') v.push_back(12);  
        else if(s[i]=='K') v.push_back(13);  
        else if(s[i]=='A') v.push_back(14);  
        else if(s[i]=='2') v.push_back(15);  
        else if(s[i]==' ') continue;  
        else v.push_back(s[i]-'0');  
    }  
    return v;  
}  
int main(){  
    string s;  
    getline(cin, s);  
    unsigned int k=s.find('-');  
    int n=s.size();  
    string s1=s.substr(0,k);  
    string s2=s.substr(k+1);  
    if(s1=="joker JOKER"||s2=="joker JOKER"){  
        cout<<"joker JOKER"<<endl;  
        return 0;  
    }  
    vector<int> v1=helper(s1);  
    vector<int> v2=helper(s2);  
    if(v1.size()==4&&v2.size()==4){  
        if(v1[0]<v2[0]) cout<<s2<<endl;  
        else cout<<s1<<endl;  
        return 0;  
    }  
        if(v1.size()==4) cout<<s1<<endl;  
        else if(v2.size()==4) cout<<s2<<endl;  
        else if(v1.size()!=v2.size()) cout<<"ERROR"<<endl;  
        else if(v1[0]<v2[0]) cout<<s2<<endl;  
        else if(v1[0]>v2[0]) cout<<s1<<endl;  
        else{  
            cout<<"ERROR"<<endl;  
        }  
        return 0;     
  
  
}  

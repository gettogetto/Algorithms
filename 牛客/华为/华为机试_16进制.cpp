//写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
double power(double x,int n){
    if(n==0) return 1;
    if(n==1) return x;
    if(n&1){
        return x*power(x,n/2)*power(x,n/2);
    }else{
        return power(x,n/2)*power(x,n/2);
    }
}
int main(){
    string str;
    while(cin>>str){
        string str2=str.substr(2);
        int n=str2.size();
        long long res=0;
        for(int i=n-1;i>=0;i--){
            char c=str2[i];
            if(!isdigit(c)){
                c=toupper(c);
                res+=((c-'A')+10)*power(16.0,(n-1)-i);
            }else{
                res+=(c-'0')*power(16.0,(n-1)-i);
            }
 
 
        }
        cout<<res<<endl;
    }
}

//法二 
#include <iostream>
using namespace std;

int main()
{
    int a;
    while(cin>>hex>>a){
    	cout<<a<<endl;
    }
}

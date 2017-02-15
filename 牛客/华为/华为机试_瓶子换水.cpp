/*
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她
最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用
3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子
换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
*/
//法一 
#include<iostream>
using namespace std;
int solve(int n){
    int water=n/3;
    int gai=n%3;
    int res=water;
    while(water+gai>=2){
        if(water==0&&gai==2){
            res+=1;
            break;
        }
        //res+=water;
        gai+=water;
         
        water=gai/3;
        gai=gai%3;
        res+=water;
    }
    return res;
}
int main(){
    int n;
    while(cin>>n){
        cout<<solve(n)<<endl;
    }
     
}
//法二
//能喝的瓶数=目前空瓶数除以2
#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
    int n;
    while(cin>>n){
            cout<<n/2<<endl;
    }
    return 0;
}
 

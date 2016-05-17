#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int c=a+b;
  int sign=1;
  if(c<0) sign=-1;
  string str=to_string(c);
  int len=str.size();
  //if(sign==1&&len<=3||sign==-1&&len<=4) {
     // cout<<str<<endl;
   // return 0;
  //}
  string res;
  int i=len-1;
  int count=0;
  while(i>=0){
    if(count>=3&&count%3==0&&((sign==1)||(i!=0&&sign==-1))) res.push_back(',');
    res.push_back(str[i--]),count++;
  }
  reverse(res.begin(),res.end());
  cout<<res;

}

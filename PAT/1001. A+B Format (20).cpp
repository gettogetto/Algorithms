
/*
1001. A+B Format (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
*/
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

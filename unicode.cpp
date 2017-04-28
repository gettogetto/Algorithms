#include<iostream>
#include<bitset>
using namespace std;
      
    //得到utf8的byte数  
int getByte(int utf8)  
{  
	bitset<32> b(utf8);
	int count=0;
	for(int i=31;i>=0;i--){
		if(b[i]==0){
			count++;
		}else{
			break;
		}
	}
	return (32-count)/8+1;
}  
int utf8ToUnicode(int val)  
{  
    int result = 0x0;  
    int bytes = getByte(val);//取得utf8的字节数  
    int result1,result2,result3,result4;  
    switch(bytes){
    case 1:
        result=0xff&val;
        break;
    case 2:
        result=(0x3f&val)|((0x1f00&val)>>2);
        break;
    case 3:
        result=(0x3f&val)|((0x3f00&val)>>2)|((0x0f0000&val)>>4);
        break;
    default:
        result=(0x3f&val)|((0x3f00&val)>>2)|((0x3f0000&val)>>4)|((0x07000000&val)>>6);
    }
    return result;  
}  
long power(long v,long n){
    if(v==1) return 1;
    if(n==0) return 1;
    long res=1;
    while(n){
        if(n%2==1) res*=v;
        v*=v;
        n=n/2;
    }
    return res;
    
}
long func(string str){
	
}
int main(){
	cout<<power(2,11);
}

/*
½«¿Õ¸ñÌæ»»³É%20 

*/
#include<iostream>
#include<string>
using namespace std;
void replaceBlank(string& str){
	int count=0;
	for(int i=0;i<str.length();i++){
		if(str[i]==' '){
			count++;
		}
	}

	int len=str.size();
	int newlen=str.size()+2*count;
	str.resize(newlen);

	while(len>0){
		
		if(str[len-1]==' '){

			str[newlen-1]='0';
			str[newlen-2]='2';
			str[newlen-3]='%';
			newlen-=3;
		}else{
			
			str[newlen-1]=str[len-1];
			newlen--;
		}
		len--;
		
	}
	
}
int main(){
	string str;
	getline(cin,str);

	replaceBlank(str);
	cout<<str;
}

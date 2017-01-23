#include<string>
#include<iostream>
#include<map>
using namespace std;

char firstOccurOnce(const string& str){
	map<char,int> occurtimes;
	for(auto ch:str) occurtimes[ch]++;
	char res;
	for(auto ch:str){
		if(occurtimes[ch]==1){
			res=ch;
			break;
		}
	}
	return res;
}
int main(){
	string str;
	cin>>str;
	cout<<firstOccurOnce(str);
	return 0;
}

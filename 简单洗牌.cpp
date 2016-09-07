//54张扑克牌，分成两份，两两交叠洗牌，多少次能会到初始状态
//例如 1 2 3 4 5 6 -> 1 4 2 5 3 6 -> 1 5 4 3 2 6 
#include<iostream>
#include<vector>
using namespace std;


int flushAndCount(vector<int> oldPoke){
	int times=0;
	int n=oldPoke.size();
	vector<int>originPoke=oldPoke;
	vector<int>newPoke(n);
	int halfLen=n/2;
	while(1){
	
		for(int i=0;i<halfLen;i++){
			newPoke[2*i]=oldPoke[i];
			newPoke[2*i+1]=oldPoke[halfLen+i];
		}	
		oldPoke=newPoke;
		times++;
		if(newPoke==originPoke) break;
				
	}
	return times;
}
	

int main()
{
	vector<int>oldPoke(54);
	for(int i=0;i<oldPoke.size();i++){
		oldPoke[i]=i;
	}
	
	cout<< flushAndCount(oldPoke);
}

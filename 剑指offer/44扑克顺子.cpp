//大小王替代任何数，抽5张看是否是顺子 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional> 
using namespace std;

bool isContinuous(vector<int> num){
        if(num.size()!=5) return false;
        sort(num.begin(),num.end());
        int numberofzero=count(num.begin(),num.end(),0); 
        auto it=find_if(num.begin(),num.end(),[](int a){return a!=0;});
        int numberofgap=0;
        while(it!=num.end()-1){
            if(*(it+1)==*it) return false;
            numberofgap+=*(it+1)-*it-1;
            it++;
        }
        return numberofzero>=numberofgap;	
}

int main(){
	vector<int> v={0,1,3,4,6};
	cout<<isContinuous(v);
}

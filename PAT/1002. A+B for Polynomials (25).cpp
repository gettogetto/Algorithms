/*
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given that 1 <= K <= 10£¬0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2

*/

#include<algorithm>
#include<iostream>
#include<string>
#include<map>
#include<cstdio>
#include<iomanip>
using namespace std;
int main(){
	int k1,k2;
	map<int,float,greater<int> > m1;
	map<int,float,greater<int> > m2;
	cin>>k1;
	for(int i=0;i<k1;i++){
		int exponent;
		float coefficient;
		cin>>exponent>>coefficient;
		m1[exponent]=coefficient;
	}
	//cin.get();
	cin>>k2;
	for(int i=0;i<k2;i++){
		int exponent;
		float coefficient;
		cin>>exponent>>coefficient;
		m2[exponent]=coefficient;
	}

	auto it1=m1.begin(),it2=m2.begin();
	map<int,float,greater<int> > m3;
	while(it1!=m1.end()&&it2!=m2.end()){
        if(it1->first > it2->first){
            m3[it1->first]=it1->second;it1++;
        }else if(it1->first < it2->first){
            m3[it2->first]=it2->second;it2++;
        }else{
            m3[it1->first]=it2->second+it1->second;
            it1++;it2++;
        }
	}
	while(it1!=m1.end()){
        m3[it1->first]=it1->second;it1++;
	}
	while(it2!=m2.end()){
        m3[it2->first]=it2->second;it2++;
	}
	int count=0;
	for(auto it=m3.begin();it!=m3.end();it++){
        if(it->second!=0) count++;
	}
	cout<<count;
    for(auto it=m3.begin();it!=m3.end();it++){
        if(it->second!=0)
            printf(" %d %.1f",it->first,it->second);
    }
    cout<<endl;
    return 0;
}

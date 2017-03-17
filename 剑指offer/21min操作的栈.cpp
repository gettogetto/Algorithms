//含最小值的栈 
#include<stack>
#include<iostream>
using namespace std;
class Mystack{-
	public:
		void push(int val){
			if(mini.empty()||mini.top()>=val){
				mini.push(val);
			}else{
				mini.push(mini.top());
			}
			data.push(val);
		}
		void pop(){
			assert(data.size()>0);
			data.pop();
			mini.pop();
		}
		int min(){
			assert(data.size()>0);
			return mini.top();
		}
	private:
		stack<int>data;
		stack<int>mini;
};

int main(){
	Mystack s;
	for(int i=0;i<10;i++)
	{
		s.push(10-i);
		cout<<s.min()<<endl;
	}
	
}

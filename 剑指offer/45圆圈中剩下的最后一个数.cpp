//0 至n-1围成圆圈，从0开始每次剔除第m个数，求最后剩下的数
//例如0 1 2 3 4围成一圈，每次剔除第3个数，则剔除的数依次是2 0 4 1最后剩下3 
#include<iostream>
#include<vector>
using namespace std;
//法一 
int LastRemaining_Solution1(int n, int m)
{
    if(n<1||m<1) return -1;
    vector<int> array(n);
    int i = -1,step = 0, count = n;
    while(count>0){   //跳出循环时将最后一个元素也设置为了-1
        i++;          //指向上一个被删除对象的下一个元素。
        if(i>=n) i=0;  //模拟环。
        if(array[i] == -1) continue; //跳过被删除的对象。
        step++;                     //记录已走过的。
        if(step==m) {               //找到待删除的对象。
            array[i]=-1;
            step = 0;
            count--;
        }        
    }
    return i;//返回跳出循环时的i,即最后一个被设置为-1的元素
}
//法二见书本解释 
int LastRemaining_Solution2(int n,int m){
	if(n==0||m==0) return -1;
	int last=0;
	for(int i=2;i<=n;i++){
		last=(last+m)%i;
	}
	return last;
} 

int main(){
	int n=5;
	int m=3; 
	cout<<LastRemaining_Solution2(n,m);
}

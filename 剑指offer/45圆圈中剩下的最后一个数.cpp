//0 ��n-1Χ��ԲȦ����0��ʼÿ���޳���m�����������ʣ�µ���
//����0 1 2 3 4Χ��һȦ��ÿ���޳���3���������޳�����������2 0 4 1���ʣ��3 
#include<iostream>
#include<vector>
using namespace std;
//��һ 
int LastRemaining_Solution1(int n, int m)
{
    if(n<1||m<1) return -1;
    vector<int> array(n);
    int i = -1,step = 0, count = n;
    while(count>0){   //����ѭ��ʱ�����һ��Ԫ��Ҳ����Ϊ��-1
        i++;          //ָ����һ����ɾ���������һ��Ԫ�ء�
        if(i>=n) i=0;  //ģ�⻷��
        if(array[i] == -1) continue; //������ɾ���Ķ���
        step++;                     //��¼���߹��ġ�
        if(step==m) {               //�ҵ���ɾ���Ķ���
            array[i]=-1;
            step = 0;
            count--;
        }        
    }
    return i;//��������ѭ��ʱ��i,�����һ��������Ϊ-1��Ԫ��
}
//�������鱾���� 
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

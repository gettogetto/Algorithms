/*
������һ�������⣺��ĳ�̵�涨����������ˮƿ���Ի�һƿ��ˮ��С��������ʮ������ˮƿ����
�����Ի�����ƿ��ˮ�ȣ�������5ƿ���������£�����9����ƿ�ӻ�3ƿ��ˮ���ȵ�3ƿ���ģ������Ժ�4����ƿ�ӣ���
3���ٻ�һƿ���ȵ���ƿ���ģ���ʱ��ʣ2����ƿ�ӡ�Ȼ�������ϰ��Ƚ����һƿ��ˮ���ȵ���ƿ���ģ������Ժ���3����ƿ��
��һƿ���Ļ����ϰ塣���С��������n������ˮƿ�������Ի�����ƿ��ˮ�ȣ�
*/
//��һ 
#include<iostream>
using namespace std;
int solve(int n){
    int water=n/3;
    int gai=n%3;
    int res=water;
    while(water+gai>=2){
        if(water==0&&gai==2){
            res+=1;
            break;
        }
        //res+=water;
        gai+=water;
         
        water=gai/3;
        gai=gai%3;
        res+=water;
    }
    return res;
}
int main(){
    int n;
    while(cin>>n){
        cout<<solve(n)<<endl;
    }
     
}
//����
//�ܺȵ�ƿ��=Ŀǰ��ƿ������2
#include <iostream>
using namespace std;
int main(int argc,char *argv[]){
    int n;
    while(cin>>n){
            cout<<n/2<<endl;
    }
    return 0;
}
 

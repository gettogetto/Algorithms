/*
����һ������X���������rev(X)Ϊ��X����λ��ת����������ȥ����ǰ��0������:
��� X = 123����rev(X) = 321;
��� X = 100����rev(X) = 1.
���ڸ�������x��y,Ҫ��rev(rev(x) + rev(y))Ϊ���٣� 
��������:
����Ϊһ�У�x��y(1 �� x��y �� 1000)���Կո������


�������:
���rev(rev(x) + rev(y))��ֵ

��������:
123 100

�������:
223
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int rev(int num){
    string str=to_string(num);
    reverse(str.begin(),str.end());
    return atoi(str.data());
}

int main(){
    int num1,num2;
    cin>>num1>>num2;
    cout<<rev(rev(num1)+rev(num2));
}



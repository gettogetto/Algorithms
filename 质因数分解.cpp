
//�ֽ�������
#include<bits/stdc++.h>
using namespace std;

void Analyse(int n)
{
    //��ӡ��
    int i;
    for(i = 2;i <= sqrt(static_cast<double>(n));i++)
    {
        if(n % i == 0)
        {
            n = n/i;
            cout<<i<<"*";
            i--;
        }
    }
    cout<<n<<endl;

}
int main()
{
    int n;
    cin>>n;
    cout<<n<<" = ";
    Analyse(n);
    return 0;
}

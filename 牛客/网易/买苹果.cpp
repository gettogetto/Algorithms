/*
小易去附近的商店买苹果，奸诈的商贩使用了捆绑交易，只提供6个每袋和8个每袋的包装(包装不可拆分)。 可是小易现在只想购买恰好n个苹果，小易想购买尽量少的袋数方便携带。如果不能购买恰好n个苹果，小易将不会购买。
输入描述:
输入一个整数n，表示小易想购买n(1 ≤ n ≤ 100)个苹果


输出描述:
输出一个整数表示最少需要购买的袋数，如果不能买恰好n个苹果则输出-1

输入例子:
20

输出例子:
3
*/
#include<iostream>
using namespace std;
int count(int n){
        if(n%2!=0||n==10||n<6) return -1;//一定是偶数（6，8都是）,最小是6，10以上偶数都可以；
        if(n%8==0) return n/8;//如果拿八个拿完最好
        return 1+n/8;//对于10以上的偶数，只要对8取余数不为0，就要从前面的1或者2个8中拿出2个，把余数补为6（本来余数就是6，就不用拿）。所以+1；
}

int main(){
    int n;
    cin>>n;
    cout<<count(n);
}
/*
#include<bits/stdc++.h>
using namespace std;


//统计苹果
int CountBags(int N)
{
    int i;
    int minBag=N;//最小的袋数

    if (N&1)
        return -1;

    for (i = 0; i <= N / 6; i++)
    {
        if ((N - 6*i) % 8 == 0)
        {
            int j = (N - 6 * i) / 8;
            minBag = min(i+j,minBag);
        }
    }

    if (minBag != N)
        return minBag;
    else
        return -1;
}
int main(){
    int n;
    cin>>n;
    cout<<CountBags(n);
}
8/

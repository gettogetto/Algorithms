/*
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少种不同的幸运的袋子。 
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)


输出描述:
输出可以产生的幸运的袋子数

输入例子:
3
1 1 1

输出例子:
2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dfs(vector<int>&v,int i,int sum,int product){
    if(i>=(int)v.size()) return sum>product;
    if(v[i]>1&&sum<product) return 0;
    int res1= dfs(v,i+1,sum+v[i],product*v[i]);//选 
    while(i<(int)v.size()-1&&v[i+1]==v[i]) i++;
    int res2= dfs(v,i+1,sum,product);//不选 
    return res1+res2;
}
int solve(vector<int>&v){
	sort(v.begin(),v.end());
    return dfs(v,0,0,1);
    
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto& i:v) cin>>i;
    cout<<solve(v);
}


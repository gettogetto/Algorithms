/*
[编程题] 最长公共连续子串
牛牛有两个字符串（可能包含空格）,牛牛想找出其中最长的公共连续子串,希望你能帮助他,并输出其长度。
输入描述:
输入为两行字符串（可能包含空格），长度均小于等于50.


输出描述:
输出为一个整数，表示最长公共连续子串的长度。

输入例子:
abcde
abgde

输出例子:
2
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,0));
    int res=0;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                res=max(res,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    cout<<res;
}*/

/*
牛牛想在[a, b]区间内找到一些数满足可以被一个整数c整除,现在你需要帮助牛牛统计区间内一共有多少个这样的数满足条件？
输入描述:
首先输入两个整数a,b,（-5*10^8 ≤ a ≤ b ≤ 5*10^8)
接着是一个正整数c（1 <= c <= 1000）


输出描述:
输出一个整数表示个数。

输入例子:
0 14 5

输出例子:
3
*/
/*


#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while(a % c != 0) a++;
    if(a > b)
        cout << 0 << endl;
    else
        cout << (b - a) / c + 1 << endl;
    return 0;
}
*/


/*
牛牛手里有N根木棒,分别编号为1~N,现在他从N根里想取出三根木棒，使得三根木棒构成一个三角形,你能计算出牛牛有多少种取法吗?(考虑两种取法中使用的木棒编号有一个不一样就认为是不同的取法)。
输入描述:
首先输入一个正整数N，接下来的一行共有N个正整数表示每个木棒的长度。

N ≤ 50, 木棒的长度 ≤ 10000.


输出描述:
输出一个整数表示方法数。

输入例子:
5
1 2 3 4 5

输出例子:
3
*/
/*

#include <bits/stdc++.h>

using namespace std;

int v[55];
int check(int a, int b, int c) {
    return a < b + c && b < a + c && c < a + b;
}
int main() {
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(check(v[i], v[j], v[k])) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}*/


/*
牛牛在二维坐标系中画了N个点，且都是整点。现在牛牛想画出一个矩形，使得这N个点都在矩形内或者在矩形上。
矩形的边均平行于坐标轴。牛牛希望矩形的面积最小。请你帮助牛牛计算下最小矩形的面积。
输入描述:
首先输入一个正整数N表示点的个数（2 <= N <= 50）

接下来N行每行两个整数x, y，表示该点的坐标。绝对值均小于等于100.


输出描述:
一个整数表示最小矩形的面积。

输入例子:
2
0 1
1 0

输出例子:
1
*/
/*


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int minx = 10000, maxx = -100000, miny = 100000, maxy = -100000;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        minx = min(minx,x);
        maxx = max(maxx,x);
        miny = min(miny,y);
        maxy = max(maxy,y);
    }
    cout << (maxx - minx) * (maxy - miny) << endl;
    return 0;
}
*/

/*


牛牛在研究他自己独创的平衡数，平衡数的定义是：将一个数分成左右两部分，分别成为两个新的数。
左右部分必须满足以下两点：
1，左边和右边至少存在一位。
2，左边的数每一位相乘如果等于右边的数每一位相乘，则这个数称为平衡数。
例如：1221这个数，分成12和21的话，1*2=2*1，则称1221为平衡数，再例如：1236这个数，可以分成123和1*2*3=6，所以1236也是平衡数。而1234无论怎样分也不满足平衡数。
输入描述:
输入一个正整数（int范围内）。


输出描述:
如果该数是平衡数，输出 "YES", 否则输出 "NO"。

输入例子:
1221
1234

输出例子:
YES
NO
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    while(cin>>a){
        int n=a.size();
        if(n==1){cout<<"NO"<<endl;continue;}
        int zero=0;
        for(int i=0;i<n;i++){
			if(a[i]=='0') zero++;
        }
        if(zero>=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(zero==1){
            if(n>1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }
        long long s1=a[0]-'0',s2=1;
        for(int i=1;i<n;i++){
            s2*=(a[i]-'0');
        }

        for(int i=1;i<n&&s1<s2;i++){
            s1*=a[i]-'0';
            s2/=a[i]-'0';
            if(s1==s2){
                cout<<"YES"<<endl;
                break;
            }
        }
        if(s1!=s2) cout<<"NO"<<endl;
    }

}*/




/*
牛牛有N个字符串，他想将这些字符串分类，他认为两个字符串A和B属于同一类需要满足以下条件：
A中交换任意位置的两个字符，最终可以得到B，交换的次数不限。比如：abc与bca就是同一类字符串。
现在牛牛想知道这N个字符串可以分成几类。
输入描述:
首先输入一个正整数N（1 <= N <= 50），接下来输入N个字符串，每个字符串长度不超过50。


输出描述:
输出一个整数表示分类的个数。

输入例子:
4
abcd
abdc
dabc
bacd

输出例子:
1
*/



/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    set<string> set1;
    for(int i=0;i<n;i++){
        cin>>str;
        sort(str.begin(),str.end());
        set1.insert(str);
    }
    cout<<set1.size()<<endl;



}*/





/*
众所周知计算机代码底层计算都是0和1的计算，牛牛知道这点之后就想使用0和1创造一个新世界！牛牛现在手里有n个0和m个1，给出牛牛可以创造的x种物品，每种物品都由一个01串表示。牛牛想知道当前手中的0和1可以最多创造出多少种物品。
输入描述:
输入数据包括x+1行：

第一行包括三个整数x(2 ≤ x ≤ 20)，n(0 ≤ n ≤ 500)，m(0 ≤ m ≤ 500)，以空格分隔

接下来的x行，每行一个01串item[i]，表示第i个物品。每个物品的长度length(1 ≤ length ≤ 50)


输出描述:
输出一个整数，表示牛牛最多能创造多少种物品

输入例子:
3 3 1
1
00
100

输出例子:
2
*/
/*

#include<bits/stdc++.h>
using namespace std;
struct Need{
    int zero;
    int one;
    Need(){
        zero=0;
        one=0;
    }
};
int main(){
    int x,n,m;
    while(cin>>x>>n>>m){
       // vector<string> v(x);
        vector<Need> need(x);
        for(int i=0;i<x;i++){
        	string str;
            cin>>str;
            for(int j=0;j<str.size();j++){
                if(str[j]=='0') need[i].zero++;
                else need[i].one++;
            }
        }
        //双重背包
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        int res=0;
        for(int i=0;i<x;i++){
            for(int j=n;j>=need[i].zero;j--){
                for(int k=m;k>=need[i].one;k--){
                    dp[j][k]=dp[j-need[i].zero][k-need[i].one]+1;
                    res=max(res,dp[j][k]);

                }
            }
        }
        cout<<res<<endl;

    }

}*/
/*法二dfs
#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;

vector <string> *l;

int m, n, x;
int solve(int i, int numZeroes, int numOnes) {
    vector<string> &list = *l;
    if(i == list.size()-1) {
        for(int x = 0; x < list[i].size(); ++x) {
            if(list[i][x] == '1') --numOnes;
            if(list[i][x] == '0') --numZeroes;
        }
        if((numOnes | numZeroes) >= 0) return 1;
        else return 0;
    }
    int a = solve(i+1, numZeroes, numOnes);
    for(int x = 0; x < list[i].size(); ++x) {
            if(list[i][x] == '1') --numOnes;
            if(list[i][x] == '0') --numZeroes;
    }
    if((numOnes | numZeroes) < 0) return a;
    int b = 1 + solve(i+1, numZeroes, numOnes);
    return max(a, b);
}
int main() {
    vector<string> v;
    cin >> x >> n >> m;
    for(int i = 0; i < x; i++) {
        string tmp; cin >> tmp;
        v.push_back(tmp);
    }
    l = &v;
    cout << solve(0, n, m) << endl;
    return 0;
}*/


/*

牛牛在书上看到一种字符串叫做回文串,当一个字符串从左到右和从右到左读都是一样的,就称这个字符串为回文串。
牛牛又从好朋友羊羊那里了解到一种被称为优美的回文串的字符串,考虑一个长度为N只包含大写字母的字符串,写出它所有长
度为M的连续子串(包含所有可能的起始位置的子串,相同的子串也要计入),如果这个字符串至少有K个子串都是回文串,我们就
叫这个字符串为优美的回文串。现在给出一个N,牛牛希望你能帮他计算出长度为N的字符串有多少个是优美的回文串(每个位置都可以是'A'~'Z'的一个。)
输入描述:
输入数据包括三个整数N, M, K(2 ≤ N ≤ 11, 2 ≤ M ≤ N, 0 ≤ K ≤ 11).


输出描述:
输出一个整数,表示所求的字符串个数.

输入例子:
2 2 1

输出例子:
26
长度为2的字符串,它长度为2的子串只有它自身。长度为2的回文串有"AA","BB","CC"..."ZZ",一共26种。
*/


#include <iostream>
#include <algorithm>

using namespace std;

long long cnt[12];
long long res = 0;
int M, K, N;
char s[12];
void solve(int k, int p) {
    if(k == 0) {
        int tmp = 0;
        for(int i = 0; i < N - M + 1; i++) {
            bool ok = true;
            for(int j = 0; j < M / 2; j++) {
                if(s[i + j] != s[i + M - 1 - j]) {
                    ok = false;
                    break;
                }
            }
            if(ok) tmp++;
        }
        if(tmp >= K) {
            res += cnt[p];
        }
        return ;
    }
    for(int i = 0; i < p + 1; i++) {
        s[k - 1] = 'a' + i;
        solve(k - 1, max(p, i + 1));
    }
}
int main() {
    cin >> N >> M >> K;
    cnt[0] = 0; cnt[1] = 26;
    for(int i = 2; i <= N; i++) {
        cnt[i] = cnt[i - 1] * (26 - i + 1);
    }
    solve(N, 0);
    cout << res << endl;
}


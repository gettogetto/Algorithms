/*
[�����] ����������Ӵ�
ţţ�������ַ��������ܰ����ո�,ţţ���ҳ�������Ĺ��������Ӵ�,ϣ�����ܰ�����,������䳤�ȡ�
��������:
����Ϊ�����ַ��������ܰ����ո񣩣����Ⱦ�С�ڵ���50.


�������:
���Ϊһ����������ʾ����������Ӵ��ĳ��ȡ�

��������:
abcde
abgde

�������:
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
ţţ����[a, b]�������ҵ�һЩ��������Ա�һ������c����,��������Ҫ����ţţͳ��������һ���ж��ٸ�������������������
��������:
����������������a,b,��-5*10^8 �� a �� b �� 5*10^8)
������һ��������c��1 <= c <= 1000��


�������:
���һ��������ʾ������

��������:
0 14 5

�������:
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
ţţ������N��ľ��,�ֱ���Ϊ1~N,��������N������ȡ������ľ����ʹ������ľ������һ��������,���ܼ����ţţ�ж�����ȡ����?(��������ȡ����ʹ�õ�ľ�������һ����һ������Ϊ�ǲ�ͬ��ȡ��)��
��������:
��������һ��������N����������һ�й���N����������ʾÿ��ľ���ĳ��ȡ�

N �� 50, ľ���ĳ��� �� 10000.


�������:
���һ��������ʾ��������

��������:
5
1 2 3 4 5

�������:
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
ţţ�ڶ�ά����ϵ�л���N���㣬�Ҷ������㡣����ţţ�뻭��һ�����Σ�ʹ����N���㶼�ھ����ڻ����ھ����ϡ�
���εı߾�ƽ���������ᡣţţϣ�����ε������С���������ţţ��������С���ε������
��������:
��������һ��������N��ʾ��ĸ�����2 <= N <= 50��

������N��ÿ����������x, y����ʾ�õ�����ꡣ����ֵ��С�ڵ���100.


�������:
һ��������ʾ��С���ε������

��������:
2
0 1
1 0

�������:
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


ţţ���о����Լ�������ƽ������ƽ�����Ķ����ǣ���һ�����ֳ����������֣��ֱ��Ϊ�����µ�����
���Ҳ��ֱ��������������㣺
1����ߺ��ұ����ٴ���һλ��
2����ߵ���ÿһλ�����������ұߵ���ÿһλ��ˣ����������Ϊƽ������
���磺1221��������ֳ�12��21�Ļ���1*2=2*1�����1221Ϊƽ�����������磺1236����������Էֳ�123��1*2*3=6������1236Ҳ��ƽ��������1234����������Ҳ������ƽ������
��������:
����һ����������int��Χ�ڣ���


�������:
���������ƽ��������� "YES", ������� "NO"��

��������:
1221
1234

�������:
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
ţţ��N���ַ��������뽫��Щ�ַ������࣬����Ϊ�����ַ���A��B����ͬһ����Ҫ��������������
A�н�������λ�õ������ַ������տ��Եõ�B�������Ĵ������ޡ����磺abc��bca����ͬһ���ַ�����
����ţţ��֪����N���ַ������Էֳɼ��ࡣ
��������:
��������һ��������N��1 <= N <= 50��������������N���ַ�����ÿ���ַ������Ȳ�����50��


�������:
���һ��������ʾ����ĸ�����

��������:
4
abcd
abdc
dabc
bacd

�������:
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
������֪���������ײ���㶼��0��1�ļ��㣬ţţ֪�����֮�����ʹ��0��1����һ�������磡ţţ����������n��0��m��1������ţţ���Դ����x����Ʒ��ÿ����Ʒ����һ��01����ʾ��ţţ��֪����ǰ���е�0��1������ഴ�����������Ʒ��
��������:
�������ݰ���x+1�У�

��һ�а�����������x(2 �� x �� 20)��n(0 �� n �� 500)��m(0 �� m �� 500)���Կո�ָ�

��������x�У�ÿ��һ��01��item[i]����ʾ��i����Ʒ��ÿ����Ʒ�ĳ���length(1 �� length �� 50)


�������:
���һ����������ʾţţ����ܴ����������Ʒ

��������:
3 3 1
1
00
100

�������:
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
        //˫�ر���
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
/*����dfs
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

ţţ�����Ͽ���һ���ַ����������Ĵ�,��һ���ַ��������Һʹ��ҵ��������һ����,�ͳ�����ַ���Ϊ���Ĵ���
ţţ�ִӺ��������������˽⵽һ�ֱ���Ϊ�����Ļ��Ĵ����ַ���,����һ������ΪNֻ������д��ĸ���ַ���,д�������г�
��ΪM�������Ӵ�(�������п��ܵ���ʼλ�õ��Ӵ�,��ͬ���Ӵ�ҲҪ����),�������ַ���������K���Ӵ����ǻ��Ĵ�,���Ǿ�
������ַ���Ϊ�����Ļ��Ĵ������ڸ���һ��N,ţţϣ�����ܰ������������ΪN���ַ����ж��ٸ��������Ļ��Ĵ�(ÿ��λ�ö�������'A'~'Z'��һ����)
��������:
�������ݰ�����������N, M, K(2 �� N �� 11, 2 �� M �� N, 0 �� K �� 11).


�������:
���һ������,��ʾ������ַ�������.

��������:
2 2 1

�������:
26
����Ϊ2���ַ���,������Ϊ2���Ӵ�ֻ������������Ϊ2�Ļ��Ĵ���"AA","BB","CC"..."ZZ",һ��26�֡�
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


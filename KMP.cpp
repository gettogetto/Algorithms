#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getNext(const std::string &p, std::vector<int> &next)
{
    next.resize(p.size());
    next[0] = -1;

    int i = 0, j = -1;
    
    while (i != p.size() - 1)
    {
        if (j == -1 || p[i] == p[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
int kmp(const std::string& s, const std::string& p, const int sIndex = 0)
{
    std::vector<int>next(p.size());
    getNext(p, next);//获取next数组，保存到vector中

    int i = sIndex, j = 0;
    while(i != s.length() && j != p.length())
    {
        if (j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    return j == p.length() ? i - j: -1;
}
int main(){
	string s="aaaaaabaabcac";
	string p="abaabcac";
	vector<int>next;
	getNext(p,next);
	for(auto i:next) cout<<i<<" ";
	cout<<"\n"<<kmp(s,p,0);
}

/*[�����] ���л�ԭ
ţţ����ҵ������һ������Ϊ n ������ A��������а����˴�1��n��n������������ΪһЩԭ��������һЩλ�ã������� 10 �����������ˣ�����ţţ�ǵ��������˳��Ե������� k��˳�����ָ���� i < j �� A[i] < A[j] �Ķ����������ţţ��������������Ҫ��ĺϷ����е���Ŀ�� 
��������:
ÿ���������һ������������ÿ�����������ĵ�һ�а����������� n �� k��1 <= n <= 100, 0 <= k <= 1000000000������������ 1 �У����� n �����ֱ�ʾ���� A�����е���0�����ʾ�������λ�ã������� 10 ������


�������:
���һ�б�ʾ�Ϸ���������Ŀ��

��������:
5 5
4 0 0 2 0

�������:
2*/

#include<iostream>
#include<vector>
 
using namespace std;
 
bool find(vector<int> v,int n)    //��ѯv���Ƿ��������n
{
    for(int i = 0;i<v.size();++i)
        if(v[i]==n)
            return true;
    return false;
}
 
vector<vector<int>> pv; //ȫ�ֱ���
 
void Perm(vector<int> &v,int st)   //��v�е����ֽ���ȫ����
{
    if(st == v.size())
        pv.push_back(v);
    else
    {
        for(int i = st;i<v.size();++i)
        {
            swap(v[i],v[st]);
            Perm(v,st+1);
            swap(v[i],v[st]);
        }
    }
}
 
void change(vector<int> &v,vector<int> subv,vector<int> vpos)//��v�е�0��ȫ��֮������ֱַ����
{
    for(int i = 0;i<vpos.size();++i)
        v[vpos[i]] = subv[i];
}
 
int cal(vector<int> v)  //����˳��Եĸ���
{
    int cnt = 0;
    for(int i = 0;i<v.size()-1;++i)
        for(int j = i+1;j<v.size();++j)
            if(v[i]<v[j])
                ++cnt;
    return cnt;
}
 
int main()
{
    int n,k,tmp;
    while(cin>>n>>k)
    {
        vector<int> v,subv,vpos;
        for(int i = 0;i<n;++i)
        {
            cin>>tmp;
            v.push_back(tmp);
        }
        for(int i = 0;i<v.size();++i)
            if(v[i]==0)
                vpos.push_back(i);   //��¼��vector<int>��0��λ��
        for(int i = 1;i<=n;++i)
            if(!find(v,i))
                subv.push_back(i);
        Perm(subv,0);
        vector<int> vcnt;
        for(int i = 0;i<pv.size();++i)
        {
            change(v,pv[i],vpos);
            vcnt.push_back(cal(v));
        }
        int vcntk = 0;
        for(int i = 0;i<vcnt.size();++i)
            if(vcnt[i]==k)
                ++vcntk;
        cout<<vcntk<<endl;
    }
 
    return 0;
}

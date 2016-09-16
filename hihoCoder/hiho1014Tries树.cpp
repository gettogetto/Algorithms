#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TriesNode
{
    public:
    TriesNode()
    {
        for(int i=0;i<26;i++){
            child[i]=nullptr;
        }
        count=0;
        //ch=0;
    }
    ~TriesNode()
    {
        delete [] child;
    }
    TriesNode* child[26];
    int count;
   /// char ch;
};

class Tries
{
    public:
    Tries()
    {
        root=new TriesNode();
    }
    ~Tries()
    {
        delete root;
    }
    TriesNode* root;
    void build(const vector<string>& v)
    {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            TriesNode* tmpnode=root;
            string str=v[i];
            for(int j=0;j<str.size();j++)
            {
                if(!tmpnode->child[str[j]-'a']) tmpnode->child[str[j]-'a']=new TriesNode();
                tmpnode->child[str[j]-'a']->count++;
               // tmpnode->child[str[j]-'a']->ch=str[j];
                tmpnode=tmpnode->child[str[j]-'a'];
            }
        }
    }
    int count(const string & str)
    {
        int n=str.size();
        TriesNode *tmpnode=root;
        for(int i=0;i<n;i++){
            if(tmpnode->child[str[i]-'a']==nullptr) return 0; 
            tmpnode=tmpnode->child[str[i]-'a'];
        }
        return tmpnode->count;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    Tries tries;
    tries.build(v);
    
    int m;
    cin>>m;
    vector<string> v2(m);
    for(int i=0;i<m;i++){
        cin>>v2[i];
        cout<<tries.count(v2[i])<<endl;
    }
    return 0;
    
}



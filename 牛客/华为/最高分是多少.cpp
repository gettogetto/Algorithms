/*
[�����] ��߷��Ƕ���
��ʦ��֪����ĳĳͬѧ���У�������ߵ��Ƕ��٣�����������ģ����ʦ��ѯ�ʡ���Ȼ����ʦ��ʱ����Ҫ����ĳλͬѧ�ĳɼ�. 
��������:
�����������������ݡ�
ÿ�������һ��������������N��M��0 < N <= 30000,0 < M < 5000��,�ֱ����ѧ������Ŀ�Ͳ�������Ŀ��
ѧ��ID��Ŵ�1�ൽN��
�ڶ��а���N��������������N��ѧ���ĳ�ʼ�ɼ������е�i��������IDΪi��ѧ���ĳɼ�
��������M�У�ÿһ����һ���ַ�C��ֻȡ��Q����U������������������A,B,��CΪ'Q'��ʱ��, ��ʾ����һ��ѯ�ʲ�������ѯ��ID��A��B������A,B����ѧ�����У��ɼ���ߵ��Ƕ���
��CΪ��U����ʱ�򣬱�ʾ����һ�����²�����Ҫ���IDΪA��ѧ���ĳɼ�����ΪB��


�������:
����ÿһ��ѯ�ʲ�������һ�����������߳ɼ�.

��������:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

�������:
5
6
5
9
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int N,M;
    
    while(cin>>N>>M){
        vector<int> score(N+1,0);
        vector<int> res;
        for(int i=1;i<=N;i++) cin>>score[i];//�±�1��ʼ
        for(int i=0;i<M;i++){
            char op;
            int A,B;
            cin>>op>>A>>B;
            if(op=='Q'){
                if(A>B) swap(A,B);
                auto it=max_element(score.begin()+A,score.begin()+B+1);

                cout<<*it<<endl;
            }else if(op=='U'){
                score[A]=B;
            }

        }

    }
    return 0;
    
}



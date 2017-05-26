 //Trajan���������ͼǿ��ͨ����������ʱ����㷨
 #include<bits/stdc++.h>
 using namespace std;
 #define N 101

 int top=-1;//ջ���±�
 int timestamp=1;//��ʾ�ڵ㱻���ʵĴ���
 int dfn[N]; //dfn[i]�����������������ʱ�ڵ�i�������Ĵ���
 int low[N]; //low[i]���ڵ�i�ܹ����ݵ�������λ��ջ�еĽڵ㡣


 bool instack[N]={0};//�Ƿ���ջ��
 int stak[N];//ջ

 int nodenum=6;//�ڵ���Ŀ
 int matrix[N][N]={{0,1,1,0,0,0},
 					{0,0,0,1,0,0},
					 {0,0,0,1,1,0},
					 {1,0,0,0,0,1},
					 {0,0,0,0,0,1},
					 {0,0,0,0,0,0}};//ͼ���ڽӾ���

 int components=0;//��ͨ��������

 void trajan(int u){
    dfn[u]=low[u]=timestamp++;
    stak[++top]=u;
    instack[u]=1;
    for(int v=0;v<nodenum;v++){
        if(matrix[u][v]){//ö��uֱ�ӿɴ�Ľڵ�v
            if(!dfn[v]){//vû���ʹ�
                trajan(v);
                low[u]=min(low[u],low[v]);//�������ҵĵ�����
            }else{//������ʹ���
                if(instack[v]) low[u]=min(low[u],dfn[v]);

                //instack����ж���������Ҫ���������Ա����Ѿ�ȷ����������ͨͼ��v,��Ϊu��v�ĵ���߶�Ӱ�쵽u��low
                //Ҳ�����Ѿ�ȷ���˵���ͨͼҪ�޳������޳��İ취�����ж��仹��ջ�У���Ϊ�Ѿ�ȷ���˵���ͨͼ�ĵ�
               //instack�������do while���Ѿ���Ϊ0��(���Ѿ���ջ���޳���)
            }
        }
    }
    //DFNֵ��lowֵ��ȵĽڵ��Ǹ���ͨͼ�е�һ�������ʵ��Ľڵ㣬�ָ���ջ�����ԣ�
    //��ýڵ��������档�����ܹ�ͨ����ͣ�ĵ�ջ��
    //ֱ��������DFNֵ��lowֵ��ͬ�Ľڵ�����������ͨͼ�����еĽڵ㡣
    if(low[u]==dfn[u]){
        components++;
        int t;
        do{
            t=stak[top--];
            cout<<t<<" ";
            instack[t]=0;//����
        }while(t!=u);
        cout<<endl;
    }
 }
 int main(){
    memset(dfn,0,sizeof(dfn));                  //���ݵĳ�ʼ��
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
    trajan(0);
 }


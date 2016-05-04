#include <stdio.h>
#include <string.h>
int filter[10][10];
int stamp[9];//记录第count次划过的数字
bool visit[10];//标记是否访问过
int result;
void dfs(int count)
{
    if(count>=4)
    {
        result++;
    }
    for(int i=1; i<=9; i++)
    {
        if(count>0&&visit[filter[ stamp[count-1] ][i] ]==false)//处理跳跃情况
            continue;
        if(visit[i]==false)
        {
            visit[i]=1;
            stamp[count]=i;
            dfs(count+1);
            visit[i]=0;//回溯
        }
    }
    return ;
}
int main()
{
    memset(filter,0,sizeof(filter));
    filter[1][3]=filter[3][1]=2;
    filter[4][6]=filter[6][4]=5;
    filter[7][9]=filter[9][7]=8;
    filter[1][7]=filter[7][1]=4;
    filter[2][8]=filter[8][2]=5;
    filter[3][9]=filter[9][3]=6;
    filter[1][9]=filter[9][1]=5;
    filter[3][7]=filter[7][3]=5;
    result=0;
    visit[0]=true;
    dfs(0);
    printf("手机的九宫格图案解锁总共能绘出%d种图案\n",result);
}

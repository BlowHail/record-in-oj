#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define ll long long
#define pi 3.1415927
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
#define _int __int128_t
//cost存表格，dis做标记
int n,m,cost[105][105],dis[105][105];
int a[]={0,0,1,-1},b[]={1,-1,0,0};
int maxs=0;
//pre和ans存答案序列
struct node{
    int x,y;
}pre[105][105],ans[10005];
//第一个dfs找最大获得多少苹果
void dfs(int x, int y, int res)
{
    for(int i=0;i<4;++i){
        int x1=x+a[i],y1=y+b[i];
        if(x1<0 || y1<0 ||x1>=n ||y1>=m)
            continue;
        if(cost[x1][y1]==-2){
            maxs=max(maxs,res);
        }
        if(dis[x1][y1]==0 && cost[x1][y1]>0 ){
            dis[x1][y1]=1;
            dfs(x1,y1,res+cost[x1][y1]);
            dis[x1][y1]=0;
        }
    }
}
int p=0;
//anser把答案存到ans[]中，方便正序输出
void anser(int x,int y)
{
    if(pre[x][y].x==-1)
        return ;
    //cout<<','<<'('<<pre[x][y].x<<','<<pre[x][y].y<<')';
    ans[p].x=pre[x][y].x;
    ans[p++].y=pre[x][y].y;
    anser(pre[x][y].x,pre[x][y].y);
}
//第二个dfs寻找路径
void dfs2(int x, int y, int res)
{
    for(int i=0;i<4;++i){
        int x1=x+a[i],y1=y+b[i];
        if(x1<0 || y1<0 ||x1>=n ||y1>=m)
            continue;
        if(cost[x1][y1]==-2){
            if(res==maxs ){
                pre[x1][y1].x=x , pre[x1][y1].y=y;
                anser(x1,y1);
                return  ;
            }
        }
        if(dis[x1][y1]==0 && cost[x1][y1]>0 ){
            dis[x1][y1]=1;
            pre[x1][y1].x=x;  //标记，存下x1 y1是由谁移动而来的
            pre[x1][y1].y=y;
            dfs2(x1,y1,res+cost[x1][y1]);
            dis[x1][y1]=0;
        }
    }
}
int main ()
{
    int x,y,x2,y2;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            cin>>cost[i][j];
            if(cost[i][j]==-1)
                x=i,y=j;
            if(cost[i][j]==-2)
                x2=i,y2=j;
        }
    pre[x][y].x=-1;
    dfs(x,y,0);
    memset(dis,0,sizeof(dis));
    dfs2(x,y,0);
    for(int i=p-1;i>=0;--i)
        cout<<'('<<ans[i].x<<','<<ans[i].y<<')'<<',';
    printf("(%d,%d)\n",x2,y2);
    cout<<maxs<<endl;
    return 0;
}
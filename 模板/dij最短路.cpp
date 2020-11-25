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
using namespace std;
int dis[1005],sign[1005],cost[1005][1005];
//dis[i] 点i到点0的距离   sign标记  cost[i][j] 点i到点j的距离
void init(int n)
{
    //初始化
    memset(dis,inf,sizeof(dis));
    memset(sign,0,sizeof(sign));
    memset(cost,inf,sizeof(cost));
    //自己到自己的距离为零
    for(int i=0;i<n;++i)
        cost[i][i]=0;
}
void dijkstra (int n,int s)
{
    dis[0]=0;
    int i;
    while(1){
        int f=-1;
        for(i=0;i<n;++i)  //遍历每一个点，寻找到原点的最短距离
            if(!sign[i] && (f==-1 || dis[i]<dis[f] ))
                f=i;
        if(f==-1)
            break;
        sign[f]=1;
        for(i=0;i<n;++i)  //更新最短距离
            dis[i]=min(dis[i],dis[f]+cost[f][i]);
    }
    
}
int main ()
{
    int n,m,i,t,j,k,x,y,p;
    cin>>n;
    init(n);
    while(cin>>x>>y>>p)
        cost[x][y]=p;

    dijkstra(n,0);
    for(i=0;i<n;++i)
        cout<<dis[i]<<" ";

    return 0;
}
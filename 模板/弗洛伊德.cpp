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
#define INF 0x3f3f3f3f
using namespace std;
int dis[1005][1005],n;
void floyd (int n)
{
    int i,j,k;
    for(k=0;k<n;++k)
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
            if(dis[i][j]>dis[i][k]+dis[k][j])
                dis[i][j]=dis[i][k]+dis[k][j];
    ///floyd的核心，挨个遍历，找出最短距离
}
int main ()
{
    int n,m,i,t,j,k,x,y,p;
    scanf("%d",&n);
    memset(dis,INF,sizeof(dis)); //将距离初始化为最大值
    while(cin>>x>>y>>p)
        dis[x][y]=p;

    for(i=0;i<n;++i)     //自己到自己的距离为 0 
        dis[i][i]=0;

    floyd(n);

    for(i=0;i<n;++i){
        for(t=0;t<n;++t)
            cout<<dis[i][t]<<" ";
        cout<<endl;
    }
    return 0;
}
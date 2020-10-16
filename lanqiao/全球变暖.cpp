#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n;
int dis[1105][1105];
char cost[1105][1105];
int x[]={-1,1,0,0},y[]={0,0,-1,1};
int judge(int a,int b)
{
    for(int i=0;i<4;++i){
        if(cost[a+x[i]][b+y[i]]=='.')
            return 1;
    }
    return 0;
}
void dfs(int a, int b)
{
    dis[a][b]=1;
    for(int i=0;i<4;++i){
        int xx=a+x[i],yy=b+y[i];
        if(xx<1 ||xx>n ||yy<1 ||yy>n)
            continue;
        if( dis[xx][yy]==0 && cost[xx][yy]=='#' )
            dfs(xx,yy);
    }
}
int main ()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>cost[i][j];
    int ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            if(dis[i][j]==0 &&cost[i][j]=='#'){
                dfs(i,j);
                ans++;
            }
        }
    memset(dis,0,sizeof(dis));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            if(cost[i][j]=='#' &&judge(i,j))
                cost[i][j]='!';
        }
    int sum=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            if(dis[i][j]==0 &&cost[i][j]=='#'){
                dfs(i,j);
                sum++;
            }
        }
    ans-=sum;
    if(ans<0)
        ans=0;
    cout<<ans<<endl;

    return 0;
}
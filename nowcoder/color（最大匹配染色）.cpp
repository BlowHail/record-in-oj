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
int n,m,vis[2005],mark[2005],color[2005][2005],point[2005],x[2005],y[2005],id[2005];
vector<int>res[2005];
bool cmp(int x,int y)
{
    return point[x]>point[y]; 
}
int dfs(int k) //最大匹配
{
    for(auto p:res[k])
    {   
        if(!vis[p])
        {
            vis[p]=1;
            if(mark[p]==0 || dfs(mark[p]))
            {
                mark[p]=k;
                mark[k]=p;
                return 1;
            }
        }
    }
    return 0;
}
int main ()
{
    int T,i,t,j,k,p,sum=0,u,v,maxs;
    cin>>n>>m;
    maxs=0;
    for(i=1;i<=m;++i)
    {
        cin>>x[i]>>y[i];
        point[x[i]]++; point[y[i]]++;
        maxs=max(maxs,max(point[x[i]],point[y[i]])); 
    }
    for(i=1;i<=n;++i)
        id[i]=i;
    for(i=1;i<=maxs;++i)
    {
        for(j=1;j<=m;++j)
            if(!color[x[j]][y[j]]){
                res[x[j]].push_back(y[j]);
                res[y[j]].push_back(x[j]);
            }
        sort(id+1,id+1+n,cmp); //按照度的大小排序
        memset(mark,0,sizeof(mark));
        for(t=1,k=id[t];t<=n;k=id[++t])  //从度最大的开始匹配
            if(!mark[k]){
                memset(vis,0,sizeof(vis));
                dfs(k);
            }
        for(j=1;j<=n;++j) 
        {
            if(mark[j]){
                color[j][mark[j]]=i;
                point[j]--;
            }
            res[j].clear();
        }
    }
    cout<<maxs<<endl;
    for(i=1;i<=m;++i)
        cout<<color[x[i]][y[i]]<<endl;
    
    return 0;
}
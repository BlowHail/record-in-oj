#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
int d[maxn];//点i的度数
int x[maxn],y[maxn];
int id[maxn],col[1040][1040];
vector<int>g[maxn];
bool vis[maxn];
int match[maxn];
int n,m;
 
bool cmp(int x,int y)
{
    return d[x]>d[y];
}
bool dfs(int u)
{
    cout<<u<<endl;
    for(auto v:g[u])
    {
        
        if(!vis[v])
        {
            vis[v]=1;
            if(match[v]==0||dfs(match[v]))
            {
                match[v]=u;
                match[u]=v;
                return 1;
            }
        }
    }
    return 0;
}
void init()
{
 
    memset(match,0,sizeof(match));
    sort(id+1,id+1+n,cmp);
}
int main()
{
 
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        d[x[i]]++;
        d[y[i]]++;
        ans=max(ans,max(d[x[i]],d[y[i]]));
    }
 
    for(int i=1;i<=n;i++)id[i]=i;
    for(int i=1;i<=ans;i++)
    {
        for(int j=1;j<=m;j++)
        if(!col[x[j]][y[j]])//该边还未被标记
        {
            g[x[j]].push_back(y[j]);//存边
            g[y[j]].push_back(x[j]);
        }
        init();
            for(int j=1,k=id[j];j<=n;j++,k=id[j])//从度数最大的开始下手
        {
            if(!match[k])
            {
                memset(vis,0,sizeof(vis));
                dfs(k);
            }
        }
 
        for(int j=1;j<=n;j++)//对每一次最大匹配进行染色
        {
            if(match[j])//如果j已经匹配
            {
                col[j][match[j]]=i;//染上色
                d[j]--;
            }
            g[j].clear();
        }
 
    }
    cout<<ans<<endl;
    for(int i=1;i<=m;i++)
    cout<<col[x[i]][y[i]]<<endl;
    return 0;
}
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
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return f*x;
}
int n,m,tot=0;
struct node{
    int to,next;
}edge[200205];
int head[100205],f[100205][30],dep[100205],dis[105][100205],ds=0,bcj[100205];
void add(int u, int v)//链式前向星存图
{
    edge[++tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
    edge[++tot].to=u;
    edge[tot].next=head[v];
    head[v]=tot;
}
void dfs(int u, int father)
{
    dep[u]=dep[father]+1;
    for(int i=1;i<=20;i++) //预处理u节点跳2^i次方的位置
        f[u][i]=f[ f[u][i-1] ][i-1];
    for(int i=head[u];i;i=edge[i].next)
    {
        if(edge[i].to==father) //防止成环
            continue;
        f[edge[i].to][0]=u; //更新父节点
        dfs(edge[i].to,u);
    }
}
int lca(int x, int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    int tep=dep[x]-dep[y];
    for(int i=0;tep;++i)
    {
        if(tep&1)
            x=f[x][i];
        tep>>=1;
    }
    // for(int i=22;i>=0;i--){
    //     if(dep[f[x][i]>=dep[y]]) //如果跳了之后深度还是比y深就继续跳
    //         x=f[x][i];
    // }
    if(x==y) //重合了，代表公共祖先是其中一个点
        return x;
    
    for(int i=22;i>=0;i--){  //同时往上跳，重合了不跳，最后返回父节点
        if(f[x][i]!=f[y][i])
            x=f[x][i],
            y=f[y][i];
    }
    return f[x][0];
}
int found(int x)
{
    if(bcj[x]==x)
        return x;
    return found(bcj[x]);
}
void bfs(int k)
{
    ds++;
    dis[ds][k]=0;
    queue<int>q;
    q.push(k);
    while(!q.empty())
    {
        //cout<<"!";
        int s=q.front();q.pop();
        for(int i=head[s];i;i=edge[i].next)
        {
            //cout<<"!!"<<endl;
            if(dis[ds][edge[i].to]>dis[ds][s]+1){
                dis[ds][edge[i].to]=dis[ds][s]+1;
                q.push(edge[i].to);
            }
        }
    }
}
vector<pair<int,int>>res;
int main ()
{
    int T,i,t,j,k,p,sum=0,u,v;
    n=read();m=read();
    for(i=1;i<=n;++i)
        bcj[i]=i;
    memset(dis,0x3f,sizeof(dis));
    for(i=1;i<=m;++i){
        u=read();v=read();
        if(found(u)==found(v))
            res.push_back({u,v});
        else
            bcj[found(u)]=found(v),add(u,v);
    }
    dfs(1,0);
    for(auto h:res)
        add(h.first,h.second);
    for(auto h:res)
        bfs(h.first);
    int q;
    q=read();
    while(q--)
    {
        j=read();k=read();
        int ans=dep[j]+dep[k]-dep[lca(j,k)]*2;
        for(t=1;t<=ds;++t)
            ans=min(ans,dis[t][j]+dis[t][k]);
        printf("%d\n",ans);
    }

    return 0;
}
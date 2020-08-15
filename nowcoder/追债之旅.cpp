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
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return f*x;
}
void print(int x)
{
    if(x < 0) {putchar('-');x = -x;}
    if(x/10) print(x/10);
    putchar(x%10+'0');
}
int n,m,k,dis[1005][15],vis[1005][15],tot,head[1005],viu[15];
struct node{
    int to,next,w;
}edge[3005];
struct que{
    int w,d,u;
    bool operator < (const que&tem)const{
        return w > tem.w;
    }
};
void add(int u,int v,int w)
{
    edge[++tot].next=head[u];
    edge[tot].to=v;
    edge[tot].w=w;
    head[u]=tot;
}
void dij()
{
    memset(dis,inf,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1][0]=0;
    priority_queue<que> q;
    q.push({0,0,1});
    while(!q.empty()){
        int u=q.top().u,d=q.top().d;
        q.pop();
        if(vis[u][d])
            continue;
        vis[u][d]=1;
        for(int i=head[u];i ;i=edge[i].next){
            int to=edge[i].to;
            if(d+1<=k&&dis[to][d+1]>dis[u][d]+edge[i].w+viu[d+1]){
                dis[to][d+1]=dis[u][d]+edge[i].w+viu[d+1];
                q.push({dis[to][d+1],d+1,to});
            }
        }
    }
}
int main ()
{
    int T,i,t,j,p,sum=0;
    cin>>n>>m>>k;
    for(i=1;i<=m;++i){
        int u=read(),v=read(),w=read();
        add(u,v,w);
        add(v,u,w);
    }
    for(i=1;i<=k;++i)
        cin>>viu[i];
    dij();
    int ans=inf;
    for(i=0;i<=k;++i)
        ans=min(ans,dis[n][i]);
    if(ans==inf)
        ans=-1;
    cout<<ans<<endl;

    return 0;
}
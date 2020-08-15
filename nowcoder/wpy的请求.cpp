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
int n,m;
struct node
{
    int to,next,w,u;
    /* data */
}edge[100005];
ll head[10005],tot=0,vis[10005],dis[10005];
void add(int u,int v, int w)
{
    edge[++tot].to=v;
    edge[tot].w=w;
    edge[tot].u=u;
    edge[tot].next=head[u];
    head[u]=tot;
}
void spfa()
{
    memset(dis,inf,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(0);
    dis[0]=0;
    while(!q.empty()){
        //cout<<"!";
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u]; i ;i=edge[i].next){
            int v=edge[i].to,w=edge[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
                }
            }
        }
    }
}
int main ()
{
    int T,i,t,j,k,p,sum=0,v,u,w;
    cin>>n>>m;
    for(i=0;i<m;++i){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for(i=1;i<=n;++i)
        add(0,i,0);
    spfa();
    for(i=1;i<=m;++i){
        u=edge[i].u; v=edge[i].to; w=edge[i].w;
        printf("%d %d %d\n",u,v,dis[u]-dis[v]+w);
    }
    
    return 0;
}
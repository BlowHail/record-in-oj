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
struct node
{
    int to,next;
}edge[1000005];
int n,m,sz[1000005],tot,head[1000005],vis[1000005],ans;
void add(int u, int v)
{
    edge[++tot].next=head[u];
    edge[tot].to=v;
    head[u]=tot;
}
void dfs(int u, int p)
{
    sz[u]=1;
    int num=n-1;
    for(int i=head[u]; i ;i=edge[i].next){
        int v=edge[i].to;
        if(v==p)
            continue;
        dfs(v,u);
        num+=sz[v]*(n-sz[v]);
        sz[u]+=sz[v];
    }
    num+=sz[u]*(n-sz[u]);
    num/=2;
    if(num&1)
        ans^=vis[u];
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    n=read();
    for(i=1;i<n;++i){
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    for(i=1;i<=n;++i)
        vis[i]=read();
    dfs(1,0);
    cout<<ans<<endl;
    
    return 0;
}
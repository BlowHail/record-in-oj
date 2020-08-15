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
int n,m,head[1000005],dep[1000005],f[1000005][30],tot;
struct node{
    int to,next;
}edge[1000005];
void add(int u, int v)
{
    edge[++tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}
void dfs(int u, int father)
{
    dep[u]=dep[father]+1;
    for(int i=1;i<=20;i++)
        f[u][i]=f[ f[u][i-1] ][i-1];
    for(int i=head[u]; i ;i=edge[i].next){
        if(edge[i].to==father)
            continue;
        f[edge[i].to][0]=u;
        dfs(edge[i].to,u);
    }
}
int lca(int x, int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    for (int i = 20; i >= 0; i--) 
        if (dep[f[x][i]] >= dep[y])
            x=f[x][i];
    if(x==y)
        return x;
    for(int i=20;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int disc(int x, int y)
{
    return dep[x]+dep[y]-2*dep[lca(x,y)];
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
    dfs(1,0);
    j=read(); k=read();
    int q=read();
    for(i=1;i<=q;++i){
        int x=read(),y=read();
        int ans=disc(x,y);
        ans=min(ans,disc(x,j)+disc(k,y));
        ans=min(ans,disc(x,k)+disc(j,y));
        printf("%d\n",ans);
    }
    return 0;
}
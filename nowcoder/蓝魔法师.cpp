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
#define mod 998244353
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
ll n,m,k,head[3000],tot,vis[3000],dp[3000][3000],sz[3000],tep[3000];
struct node{
    ll to,next;
}edge[6000];
void add(int u,int v)
{
    edge[++tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot;
}
void dfs(int u, int par)
{
    dp[u][1]=1; sz[u]=1;
    for(int i=head[u]; i ;i=edge[i].next){
        int v=edge[i].to;
        if(v==par)
            continue;
        dfs(v,u);
        memset(tep,0,sizeof(tep));
        for(int p=0;p<=min(sz[u],k);p++){
            for(int q=0;q+p<=k && q<=sz[v];q++)
                tep[p+q]=(tep[p+q]%mod+dp[u][p]*dp[v][q]%mod)%mod;
        }
        for(int j=1;j<=k;j++)
            dp[u][j]=tep[j];
        sz[u]+=sz[v];
    }
    for(int i=1;i<=k;i++)
        dp[u][0]=(dp[u][0]+dp[u][i])%mod;
}
int main ()
{
    int T,i,t,j,p,sum=0;
    cin>>n>>k;
    for(i=1;i<n;++i){
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    cout<<dp[1][0]<<endl;
    return 0;
}
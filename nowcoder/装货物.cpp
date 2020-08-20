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
int n,m,x,w,a[25],vis[25];
int dfs(int k)
{
    if(k==n+1)
        return 1;
    for(int i=1;i<=min(k,x);i++){
        if(vis[i]+a[k]<=w){
            vis[i]+=a[k];
            if(dfs(k+1))
                return 1;
            vis[i]-=a[k];
        }
    }
    return 0;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while (T--)
    {
        cin>>n>>x>>w;
        for(i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+1+n,greater<int>());
        memset(vis,0,sizeof(vis));
        if(dfs(1))
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
        /* code */
    }
    
    
    return 0;
}
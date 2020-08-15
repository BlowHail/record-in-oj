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
int dp[105][20005],vis[20005],pp[15];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;++i)
        {
            k=read();
            for(j=1;j<=k;++j){
                t=read(); p=read();
                dp[t][i]=p;
            }
        }
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        for(i=1;i<=100;++i){
            memset(pp,0,sizeof(pp));
            for(j=1;j<=n;++j){
                if(dp[i][j] && vis[j] )
                    pp[ dp[i][j] ]=1;
            }
            for(j=1;j<=n;++j){
                if(pp[ dp[i][j] ])
                    vis[j]=1;
            }
        }
        int f=1;
        for(i=1;i<=n;i++){
            if(vis[i] &&f){
                printf("%d",i);
                f=0;
            }
            else if (vis[i] )
                printf(" %d",i);
        }
        cout<<endl;

    }
    
    return 0;
}
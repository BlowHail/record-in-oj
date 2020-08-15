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
int n,m,dp[305][305],via[350],sum[305][305];
int main ()
{
    int T,i,t,j,k,p;
    cin>>n>>m;
    memset(dp,inf,sizeof(dp));
    for(i=1;i<=n;++i){
        for(t=1;t<=m;++t)
            via[t]=read();
        sort(via+1,via+1+m);
        for(t=1;t<=m;++t)
            sum[i][t]=sum[i][t-1]+via[t];
    }
    dp[0][0]=0;
    for(i=1;i<=n;++i){
        for(j=i;j<=min(n,i*m);j++){
            for(k=i-1;k<=min(n,i*m-m)&&k<=j;k++)
                dp[i][j]=min(dp[i][j],dp[i-1][k]+sum[i][j-k]+(j-k)*(j-k));
        }
    }
    cout<<dp[n][n]<<endl;
    
    return 0;
}
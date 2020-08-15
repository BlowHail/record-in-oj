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
inline __int128_t read()
{
    __int128_t x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return f*x;
}
void print(__int128_t x)
{
    if(x < 0) {putchar('-');x = -x;}
    if(x/10) print(x/10);
    putchar(x%10+'0');
}
__int128_t n,m,dp[100][100],a[100][100];
int main ()
{
    __int128_t T,i,t,j,k,p,sum=0;
    n=read();m=read();
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            a[i][j]=read();
    for(i=1;i<=n;++i)
    {
        memset(dp,0,sizeof(dp));
        for(int len=1;len<=m;++len)
        {
            for(int l=1;l<=m-len+1;l++){
                int r=l+len-1;
                dp[l][r]=max( dp[l][r-1]+a[i][r] ,dp[l+1][r]+a[i][l] );
                dp[l][r]*=2;
            }
        }
        sum+=dp[1][m];
    }
    print(sum);
    return 0;
}
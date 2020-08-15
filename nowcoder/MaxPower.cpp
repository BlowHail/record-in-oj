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
int n,m,a[55][55],dp[55][55][1500],f[55];
int main ()
{
    int T,i,t,k,j,p,sum=0;
    while(cin>>n>>m){
        memset(dp,0,sizeof(dp));
        sum=0;
        for(i=1;i<=n;++i){
            f[i]=f[i-1]+i;
            for(j=1;j<=n-i+1;++j){
                cin>>a[i][j];
                a[i][j]+=a[i-1][j];
            }
        }
        for(i=n;i>=1;--i){
            for(j=0;j<=n-i+1;j++){
                for(k=f[j];k<=m;++k){
                    for(p=max(0,j-1);p<n-i+1;p++)
                    dp[i][j][k]=max(dp[i][j][k],dp[i+1][p][k-j]+a[j][i]);
                sum=max(sum,dp[i][j][k]);
                }
            }
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
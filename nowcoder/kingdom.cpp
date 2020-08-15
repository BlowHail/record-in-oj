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
int n,m,dp[10000][10000],ans[10000];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>n;
    for(i=1;i<=n;++i){
        for(j=1;j<i;++j){
            ans[i]=max(ans[i],dp[i-j-1][j]+i-j-1+ans[j]);
        }
        for(j=1;j<=n;++j)
        {
            if(i>=j)
                dp[i][j]=dp[i-j][j]+ans[j];
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    cout<<ans[n]<<endl;
    return 0;
}
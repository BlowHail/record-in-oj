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
int dp[105][10105],va[105];
int main ()
{
    int T,n,m,i,t,j,k,p;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>va[i];
    memset(dp,-inf,sizeof(dp));
    dp[0][0]=0;
    for(i=1;i<=n;++i)
        for(t=0;t<=10000;++t)
        {
            dp[i][t]=max(dp[i-1][t],max(dp[i-1][t+va[i]],dp[i-1][abs(t-va[i])])+va[i]);
        }
    int maxs=0;
    for(i=0;i<=m;++i)
    //cout<<dp[n][i]<<endl;
        maxs=max(maxs,dp[n][i]);
    cout<<maxs<<endl;
    
    return 0;
}
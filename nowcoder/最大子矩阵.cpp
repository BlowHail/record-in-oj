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
int sum[105][5],dp[105][105][12],num[105][5];
int main ()
{
    
    int T,n,m,i,t,j,k,p;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j){
            cin>>num[i][j];
            sum[i][j]=sum[i-1][j]+num[i][j]; //计算前缀和
        }
    
    if(m==1)
    {
        for(i=1;i<=n;++i)
            for(int kk=1;kk<=k;++kk){//m==1的时候，相当于求最大m子串和
                dp[i][0][kk]=max(dp[i-1][0][kk],dp[i-1][1][kk]);
                dp[i][1][kk]=max(dp[i-1][1][kk],max(dp[i-1][1][kk-1],dp[i-1][0][kk-1]))+num[i][1];
            }
        p=max(dp[n][1][k],dp[n][0][k]);
        cout<<p<<endl;
    }
    else 
    {
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                for(int kk=1;kk<=k;++kk)
                {
                    dp[i][j][kk]=max(dp[i-1][j][kk],dp[i][j-1][kk]); 
                    for(t=0;t<i;++t)
                        dp[i][j][kk]=max(dp[i][j][kk],dp[t][j][kk-1]+sum[i][1]-sum[t][1]); //在第一列选区间
                    for(t=0;t<j;++t)
                        dp[i][j][kk]=max(dp[i][j][kk],dp[i][t][kk-1]+sum[j][2]-sum[t][2]); //在第二列选区间
                    if(i==j)
                        for(t=0;t<j;++t) 
                            dp[i][j][kk]=max(dp[i][j][kk],dp[t][t][kk-1]+sum[i][1]-sum[t][1]+sum[j][2]-sum[t][2]);
                }
        cout<<dp[n][n][k]<<endl;
    }
    return 0;
}
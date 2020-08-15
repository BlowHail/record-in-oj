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
int n,m;
int dp[1005][1005];
string s;
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>s;
    int l=s.length();
    memset(dp,inf,sizeof(dp));
    for(i=0;i<=l;++i)
        dp[i][i]=1;
    for(i=2;i<=l;++i){
        for(j=0;j<=l-i;j++){
            k=j+i-1;
            if(s[j]==s[k])
                dp[j][k]=min(dp[j][k-1],dp[j+1][k]);
            else{
                for(int u=j;u<k;++u)
                    dp[j][k]=min(dp[j][u]+dp[u+1][k],dp[j][k]);
            }
        }
    }
    cout<<dp[0][l-1]<<endl;
    
    return 0;
}
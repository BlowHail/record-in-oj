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
int n,m,dp[5006][5006],ans[5006][5006];
int main ()
{
    int T,i,t,j,k,q,sum=0;
    cin>>n;
    for(i=1;i<=n;++i){
        cin>>t;
        dp[i][i]=ans[i][i]=t;
    }
    for(int len=2;len<=n;++len){
        for(int l=1;l+len-1<=n;++l){
            int r=l+len-1;
            dp[l][r]=dp[l][r-1]^dp[l+1][r];
            ans[l][r]=max(dp[l][r],max(ans[l][r-1],ans[l+1][r]));
        }
    }
    cin>>q;
    while(q--){
        cin>>j>>k;
        cout<<ans[j][k]<<endl;
    }
    
    return 0;
}
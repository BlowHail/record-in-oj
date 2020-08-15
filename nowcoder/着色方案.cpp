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
ll n,m,dp[17][17][17][17][17][7],vis[17];
ll dfs(int a, int b, int c, int d, int e, int las)
{
    if(a+b+c+d+e==0)
        return 1;
    ll ans=0;
    if(dp[a][b][c][d][e][las])
        return dp[a][b][c][d][e][las];
    if(a) ans=(ans+ (a-(las==2))*dfs(a-1,b,c,d,e,1) );
    if(b) ans=(ans+ (b-(las==3))*dfs(a+1,b-1,c,d,e,2) );
    if(c) ans=(ans+ (c-(las==4))*dfs(a,b+1,c-1,d,e,3) );
    if(d) ans=(ans+ (d-(las==5))*dfs(a,b,c+1,d-1,e,4) );
    if(e) ans=(ans+ e*dfs(a,b,c,d+1,e-1,5) );
    return dp[a][b][c][d][e][las]=ans%mod;
}
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>k;
    for(i=0;i<k;++i){
        cin>>p;
        vis[p]++;
    }
    sum=dfs(vis[1],vis[2],vis[3],vis[4],vis[5],0);
    cout<<sum<<endl;
    
    return 0;
}
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
int n,m,dp[45][45][45][45],aa[1005],bb[6];
int dfs(int a, int b, int c, int d)
{
    if(a+b+c+d==0)
        return aa[n];
    if(dp[a][b][c][d])
        return dp[a][b][c][d];
    int l=bb[1]-a+2*(bb[2]-b)+3*(bb[3]-c)+4*(bb[4]-d)+1;
    int ans=0;
    if(a) ans =max(ans,aa[l]+dfs(a-1,b,c,d));
    if(b) ans =max(ans,aa[l]+dfs(a,b-1,c,d));
    if(c) ans =max(ans,aa[l]+dfs(a,b,c-1,d));
    if(d) ans =max(ans,aa[l]+dfs(a,b,c,d-1));
    return dp[a][b][c][d]= ans;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>aa[i];
    for(i=1;i<=m;++i){
        cin>>p;
        bb[p]++;
    }
    sum=dfs(bb[1],bb[2],bb[3],bb[4]);
    cout<<sum<<endl;
    
    return 0;
}
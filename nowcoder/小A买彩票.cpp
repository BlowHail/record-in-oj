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
int n,m;
ll dp[130][40];
ll gcd(ll j,ll k)
{
    if(!j)
        return k;
    return gcd(k%j,j);
}
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>n;
    dp[0][0]=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=4*i;++j){
            if(j>=1)
                dp[j][i]+=dp[j-1][i-1];
            if(j>=2)
                dp[j][i]+=dp[j-2][i-1];
            if(j>=3)
                dp[j][i]+=dp[j-3][i-1];
            if(j>=4)
                dp[j][i]+=dp[j-4][i-1];
        }
    p=0;
    for(j=3*n;j<=120;++j)
        if(dp[j][n])
            p+=dp[j][n];
    //for(j=1;j<=10;++j)
    //cout<<dp[j][n]<<" ";
    sum=pow(4,n);
    k=gcd(p,sum);
    cout<<p/k<<"/"<<sum/k<<endl;

    return 0;
}
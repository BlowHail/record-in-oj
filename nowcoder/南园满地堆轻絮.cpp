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
using namespace std;
ll n,m,sa,sb,sc,sd,mod,a[5000005],b;
ll fun(ll x)
{
    ll a=(sa*x%mod)*x%mod *x%mod,b=sb*x%mod*x%mod,c=sc*x%mod,d=sd%mod;
    return ((((a+b)%mod)+c)%mod+d)%mod;
}
int check(int x)
{
    b=a[1]-x;
    for(int i=2;i<=n;++i)
        if(a[i]>=b)
            b=max(b,a[i]-x);
        else if(a[i]<b-x)
            return 0;
    return 1;
}
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>n>>sa>>sb>>sc>>sd>>a[1]>>mod;
    for(i=2;i<=n;++i)
        a[i]=(fun(a[i-1])+fun(a[i-2]))%mod;
    ll l=0,r=inf,ans=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid))
            r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
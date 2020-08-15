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
ll a[200005],maxn[200005],sum[200005];
int main ()
{
    ll n,T,m,i,t,j,k,p=1;
    cin>>T;
    while (T--)
    {
        cin>>n>>k;
        maxn[n-k+2]=-1e18;
        //cout<<maxn[n-k+2]<<endl;
        for(i=1;i<=n;++i){
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(i=n-k+1;i>k;i--)
            maxn[i]=max(maxn[i+1],sum[i+k-1]-sum[i-1]);
        ll maxs=-1e18;
        for(i=k;i+k<=n;++i)
            maxs=max( maxs , sum[i]-sum[i-k]+maxn[i+1] );
        cout<<maxs<<endl;
    }
    return 0;
}
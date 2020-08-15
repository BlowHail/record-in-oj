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
ll n,m;
ll a[200005],b[200005];
bool cmp(ll x,ll y)
{
    return x>y;
}
int main ()
{
    ll T,i,t,j,k,p,h;
    ll sum=0;
    cin>>t;
    while (t--)
    {
        cin>>n>>k;
        h=0;
        for(i=0;i<n;++i)
            scanf("%lld",&a[i]);
        for(i=0;i<k;++i){
            scanf("%lld",&b[i]);
            if(b[i]==1)
                h++;
        }
        sort(a,a+n);
        sort(b,b+k,cmp);
        sum=0;
        j=0;p=n-1-h;
        k-=h;
        for(i=n-1;i>=n-h;i--)
            sum+=a[i]*2;
        
        for(i=0;i<k;++i)
        {
            
                sum+=a[p]+a[j];
                p--;j+=b[i]-1;
            
        }
        cout<<sum<<endl;
    }
    
    
    return 0;
}
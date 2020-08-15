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
ll a[200005];
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>t;
    while (t--)
    {
        cin>>n;
        sum=0;
        for(i=0;i<n;++i){
            scanf("%lld",&a[i]);
            if(i%2==0)
                sum+=a[i];
        }
        k=0;
        ll maxs=0;
        for(i=1;i<n;i+=2)
        {
            p=a[i]-a[i-1];
            k+=p;
            if(k<0)
                k=0;
            maxs=max(maxs,k);
        }
        k=0;
        for(i=2;i<n;i+=2)
        {
            p=a[i-1]-a[i];
            k+=p;
            if(k<0)
                k=0;
            maxs=max(maxs,k);
        }
        sum+=maxs;
        cout<<sum<<endl;
        /* code */
    }
    
    
    return 0;
}
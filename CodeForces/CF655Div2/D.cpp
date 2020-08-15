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
ll a[200005];
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>n;
    for(i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    
    sum=a[n];
    for(i=2;i<n;i+=2)
        sum+=a[i];
    cout<<sum<<endl;
    return 0;
}
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
ll a[2000005];
int main ()
{
    ll T,i,t,j,p,sum=0;
    a[3]=4; a[4]=4;
    for(i=5;i<=2000000;i++)
        a[i]=(2*a[i-2]%mod+a[i-1]%mod+(i%3==0)*4)%mod;

    cin>>t;
    while (t--)
    {
        /* code */
        cin>>n;
        cout<<a[n]<<endl;
    }
    
    return 0;
}
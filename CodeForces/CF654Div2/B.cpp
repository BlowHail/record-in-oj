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
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>T;
    while (T--)
    {
        cin>>n>>k;
        sum=0;
        p=min(n,k);

        sum=(1+p)*p/2;

        if(n<=k)
            sum-=n-1;
        cout<<sum<<endl;
        /* code */
    }
    
    
    return 0;
}
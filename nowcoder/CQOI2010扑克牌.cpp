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
int a[100],n,m;
int poker(ll mid)
{
    ll sum=0;
    for(int i=0;i<n;++i)
        if(a[i]<mid)
            sum+=mid-a[i];

    if(sum>mid ||sum >m)
        return 0;
    return 1;
}
int main ()
{
    int T,i,t,p;
    cin>>n>>m;
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
    ll j=0,k=1000000000;
    while(j<k)
    {
        ll mid=(j+k+1)/2;
        if(poker(mid))
            j=mid;
        else 
            k=mid-1;
    }
    cout<<j<<endl;

    return 0;
}
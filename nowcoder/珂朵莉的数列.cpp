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
ll a[1000005],b[1000005],c[1000005];
ll lowbit(ll i)
{
    return i&-i;
}
void add(ll i,ll p)
{
    while (i<=n)
    {
        c[i]+=p;
        i+=lowbit(i);
    }
}
ll getsum(ll k)
{
    ll res=0;
    while(k)
    {
        res+=c[k];
        k-=lowbit(k);
    }
    return res;
}
void Print(__int128_t x)
{
    if(x==0)
        return ;
    Print(x/10);
    putchar(x%10+'0');
}
int main ()
{
    ll T,i,t,j,k,p;
    cin>>n;
    for(i=1;i<=n;++i)
        scanf("%lld",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;++i)
        a[i]=lower_bound(b+1,b+n+1,a[i])-b;
    __int128_t sum=0;
    for(i=1;i<=n;++i)
    {
        sum+=(getsum(n)-getsum(a[i]))*(n-i+1);
        add(a[i],i);
    }
    if(sum==0)
        cout<<"0";
    else 
        Print(sum);
    cout<<endl;
    return 0;
}
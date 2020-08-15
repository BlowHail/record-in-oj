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
#define _int __int128_t
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return f*x;
}
void print(int x)
{
    if(x < 0) {putchar('-');x = -x;}
    if(x/10) print(x/10);
    putchar(x%10+'0');
}
ll n,m,a[300006],w[300006],sum[300006];
int main ()
{
    int T,i,t,j,k,p;
    cin>>n;
    for(i=1;i<=n;++i){
        a[i]=read();
        sum[i]=(sum[i-1]+a[i])%mod;
    }
    for(i=1;i<=n;++i)
        w[i]=read();
    ll res=0,ans=0;
    for(i=1;i<=n;++i){
        res+=sum[n-i+1]-sum[i-1]+mod;
        res%=mod;
        ans=(ans+res*w[i]%mod)%mod;
    }
    cout<<ans<<endl;

    return 0;
}
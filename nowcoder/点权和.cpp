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
ll n,m,fa[100005],a[100005],b[100005],c[100005],sizes[100005];
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>n>>m;
    for(i=2;i<=n;++i){
        p=read();
        sizes[p]++;
        fa[i]=p;
    }
    ll x,y,z;
    for(j=1;j<=m;++j){
        i=read();
        a[i]++;
        if(fa[i]) b[fa[i]]++;
        if(fa[fa[i]]) c[fa[fa[i]]]++;

        x=(a[i]+b[i]+a[fa[i]])%19260817; //自己的贡献
        y=(a[fa[i]]+b[fa[i]]+a[fa[fa[i]]])%19260817; //父节点贡献
        z=(b[i]+c[i]+sizes[i]*a[i]%19260817)%19260817;//儿子节点贡献
        ll res=(x+y+z)%19260817;
        sum=(sum+res*j%19260817)%19260817;
    }
    cout<<sum<<endl;
    
    return 0;
}
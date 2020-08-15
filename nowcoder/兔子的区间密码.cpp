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
inline ll read()
{
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return f*x;
}
void print(ll x)
{
    if(x < 0) {putchar('-');x = -x;}
    if(x/10) print(x/10);
    putchar(x%10+'0');
}
ll n,m;
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--)
    {
        j=read(); k=read();
        p=j^k;
        sum=0;
        while(p){
            p>>=1;
            sum=sum<<1|1;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
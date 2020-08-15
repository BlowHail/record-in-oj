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
int n,m;
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--){
        sum=0;
        n=read(); m=read(); p=read();
        double bb=100000000.0-1.0*m*p/100.0;
        //ll bb=aa;
        //cout<<bb<<endl;
        ll pp=bb;
        pp=100000000-pp;
        
            n-=m;
            if(n>=m){
                k=n/pp;
                sum+=k;
                n-=pp*k;
            }
            n+=m;
            while(n>=m){
                n-=pp;
                sum++;
            }
        printf("%lld\n",sum);
    }
    
    return 0;
}
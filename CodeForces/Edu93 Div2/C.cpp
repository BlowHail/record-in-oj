#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
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
ll n,m,sum;
int main ()
{
    int T,i,t,j,k,p;
    string s;
    T=read();
    while(T--)
    {
        n=read();
        cin>>s;
        s='0'+s;
        ll l=n;
        sum=0;
        ll sums=0;
        map<ll, ll> mp;
        mp.clear();
        for(i=1;i<=l;++i){
            sum+=s[i]-'0'-1;
            if(sum==0)
                sums++;
            sums+=mp[sum];
            mp[sum]++;
        }
        
        printf("%lld\n",sums);
    }
    return 0;
}
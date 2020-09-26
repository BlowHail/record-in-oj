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
ll n,m;
int a[2000008];
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld %lld %lld",&n,&m,&k);
        ll sum=0;
        sum+=(k-1);
        memset(a,0,sizeof(a));
        for(i=1;i<=m;++i){
            scanf("%lld",&a[i]);
        }
        sort(a+1,a+1+m);
        for(i=m;i>=2;i--){
            sum+=fabs(a[i]-k)*2;
        }
        if(a[1]<k)
            sum+=k-1;
        else
        {
            sum+=k-1+fabs(a[1]-k)*2;
        }
        
        printf("%lld\n",sum);
    }
    
    return 0;
}
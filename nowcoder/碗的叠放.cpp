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
void qprint(int x)
{
    if(x < 0) {putchar('-');x = -x;}
    if(x/10) qprint(x/10);
    putchar(x%10+'0');
}
int n,m,vis[15];
struct node{
    int h,r1,r2;
}a[15];
int wan(int i, int h, int j)
{
    if(i==n)
        return h+a[i].h;
    for(int t=1;t<=n;++t)
    {
        if(!vis[t]){
            vis[t]=1;
            
        }
    }
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i].h>>a[i].r1>>a[i].r2;
    
    
    return 0;
}
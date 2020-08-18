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
ll n,k,m,col[65];
struct node
{
    ll color,x;
    /* data */
}a[1000005];
bool cmp(node x, node y){
    return x.x<y.x;
}
ll check(){
    for(int i=1;i<=k;++i){
        if(col[i]==0)
            return 0;
    }
    return 1;
}
int main ()
{
    ll T,i,t,j,p,sum=0;
    cin>>n>>k;
    p=0;
    for(i=1;i<=k;++i){
        cin>>T;
        for(j=1;j<=T;++j){
            a[++p].x=read();
            a[p].color=i;
        }
    }
    sort(a+1,a+n+1,cmp);
    ll l=1,ans=inf;
    for(int i=1;i<=p;++i){
        col[a[i].color]++;
        if(check())
        {
            while (check())
            {
                col[a[l].color]--;
                l++;
            }
            l--;
            col[a[l].color]++;
            ans=min(ans,a[i].x-a[l].x);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
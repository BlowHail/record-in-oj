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
int n,m;
struct node{
    int w,t;
}ro[1005],lo[1005];
bool cmp(node x, node y)
{
    return x.w>y.w;
}
bool tep(node x, node y)
{
    return x.t<y.t;
}
int main ()
{
    int T,i,t,j,k,l,d,sum=0;
    cin>>m>>n>>k>>l>>d;
    for(i=1;i<=d;++i){
        int x=read(),y=read(),p=read(),q=read();
        if(x==p){
            j=min(y,q);
            lo[j].w++;
            lo[j].t=j;
        }
        else{
            j=min(x,p);
            ro[j].w++;
            ro[j].t=j;
        }
    }
    sort(ro+1,ro+m+1,cmp);
    sort(lo+1,lo+n+1,cmp);
    sort(ro+1,ro+k+1,tep);
    sort(lo+1,lo+l+1,tep);
    for(i=1;i<=k;++i){
        if(i!=k)
            printf("%d ",ro[i].t);
        else 
            printf("%d\n",ro[i].t);
    }
    for(i=1;i<=l;++i){
        if(i!=l)
            printf("%d ",lo[i].t);
        else 
            printf("%d\n",lo[i].t);
    }

    
    return 0;
}
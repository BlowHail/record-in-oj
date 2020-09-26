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
int a[1000006],fa[1000006];
int find(int x){
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
void join(int a, int b)
{
    int j=find(a), k=find(b);
    fa[j]=k;
}
int main ()
{
    int T,i,t,j,k,p,sum=0,x,y;
    cin>>n>>k;
    for(i=1;i<=n;i++)
        fa[i]=i;
    for(i=1;i<n;++i){
        scanf("%d %d",&x,&y);
        join(x,y);
    }
    for(i=1;i<=n;++i){
        a[ fa[i] ]=1;
        //cout<<fa[i]<<endl;
    }
    for(i=1;i<=n;++i){
        if(a[i])
            sum++;
    }
    cout<<sum<<endl;
    return 0;
}
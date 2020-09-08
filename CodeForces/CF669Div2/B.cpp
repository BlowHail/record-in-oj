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
struct node
{
    int a,c;
}a[10004];
bool cmp(node x, node y){
    if(x.c==y.c)
        return x.a<y.a;
    return x.c>y.c;
}
bool ccc(node x, node y){
    return x.a>y.a;
}
int n,m;
int gcd(int x,int y)
{
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--){
        cin>>n;
        int maxs=0,maxsi=0;
        for(i=1;i<=n;++i){
            scanf("%d",&a[i].a);
            a[i].c=a[i].a;
        }
        sort(a+1,a+1+n,ccc);
        for(i=1;i<=n;++i){
            for(int j=i;j<=n;++j)
                a[j].c=gcd(a[i].c,a[j].c);
            sort(a+1,a+n+1,cmp);
        }
        for(i=1;i<n;++i){
            printf("%d ",a[i].a);
        }
        printf("%d\n",a[n].a);

    }
    
    return 0;
}
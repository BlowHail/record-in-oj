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
int n,m,a[100005];

int main ()
{
    int T,i,t,j,k,p,sum=0; // b 1352  y 650 q 
    p='q'-'a'+1;
    cin>>n;
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int maxs=0;
    p=0;
    int f=1;
    for(i=1;i<=n;i<<=1){
        sum=0;
        //cout<<i<<endl;
        p++;
        for(k=i;k<(i<<1)&&k<=n;++k)
            sum+=a[k];
        if(maxs<sum)
            maxs=sum,f=p;
    }
    cout<<f<<endl;

    return 0;
}
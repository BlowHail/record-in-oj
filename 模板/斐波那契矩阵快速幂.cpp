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
#define mod 10000
using namespace std;

struct node {
ll a[3][3];
};
node matrix(node x,node y) //计算矩阵相乘
{
    int i,t,u;
    node res;
    res.a[0][0]=res.a[1][0]=res.a[0][1]=res.a[1][1]=0;
    for (i=0;i<2;++i)
        for (t=0;t<2;++t)
            for (u=0;u<2;++u)
                res.a[i][t]=(res.a[i][t]%mod+x.a[i][u]*y.a[u][t]%mod)%mod;
    return res;
}
node quickpow(node a,ll n)
{
    node sum;
    sum.a[0][0]=sum.a[1][1]=1;
    sum.a[0][1]=sum.a[1][0]=0;
    while(n)  //此处只是将快速幂的整数换成了矩阵相乘，其他没有差别
    {
        if (n&1)
            sum=matrix(sum,a);
        n>>=1;
        a=matrix(a,a);
    }
    return sum;
}
int main ()
{
    ll n,m,i,t,j,k;
    node a,b;
    while(scanf("%lld",&n))
    {
        if (n==-1)
            break;
        a.a[0][0]=a.a[0][1]=a.a[1][0]=1;
        a.a[1][1]=0;
        b=quickpow(a,n);
        printf("%lld\n",b.a[1][0]);
    }
    
    return 0;
}
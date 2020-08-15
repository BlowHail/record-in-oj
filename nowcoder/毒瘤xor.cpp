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
int n,m;
int a[2][40][100005];
int main ()
{
    int T,i,t,j,k,p=1;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&t);
        for(p=1;p<=32;++p)
        {
            a[1][p][i]=a[1][p][i-1]+1;  //先让0的个数每次都增加，如果这一位是1，再改回上一项的数量
            a[0][p][i]=a[0][p][i-1];
            if(t) 
            {
            a[0][p][i]=(t&1)+a[0][p][i-1];  //取二进制最后一位
            if((t&1)==1)
                a[1][p][i]=a[1][p][i-1]; //将0的个数修改为上一项的
                t=t>>1;
            }
                
        }
    }
    cin>>m;
    while (m--)
    {
        cin>>j>>k;
        ll res=0;
        for(i=31;i>0;--i)
        {
            res=res<<1;
            //如果1的个数小于了0的个数，就让当前位 为 1 ，因为要求较小的解，所以0和1数量相等的时候也要让当前位为0
            if( (a[0][i][k]-a[0][i][j-1]) < (a[1][i][k]-a[1][i][j-1]))
                res++;
            
        }
        cout<<res<<endl;
    }
    return 0;
}
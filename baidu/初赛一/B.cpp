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
double a[]={0,1,1.7,2.0,2.3,2.7,3.0,3.3,3.7,4.0,4.3};
int b[]={0,60,62,65,67,70,75,80,85,90,95};
double sum=0,maxs=0;
void gree(int t)
{
    if(t>4)
        return ;
    for(int i=0;i<11;++i)
    {
        n-=b[i];
        if(n>=0){
            sum+=a[i];
            maxs=max(maxs,sum);
            gree(t+1);
            sum-=a[i];
        }
        n+=b[i];
    }
}
int main ()
{
    int T,i,t,j,k,p;
    cin>>T;
    while(T--)
    {
        cin>>n;
        maxs=0;sum=0;
        gree(1);
        printf("%.1f\n",maxs);
    }
    
    return 0;
}
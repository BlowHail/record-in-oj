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
int n,m,id[105];
struct node{
    double r1,r2,h;
}a[105];
double f[105];
double slope(int i)
{
    return  (a[i].r2-a[i].r1)/a[i].h;
}
double solve(int i,int j)
{
    if(a[i].r1>a[j].r2)
        return a[j].h;
    if(a[i].r2<a[j].r1)
        return 0;
    if(slope(i)<=slope(j)){
        if(a[i].r1<=a[j].r1)
            return 0;
        return a[j].h*(a[i].r1-a[j].r1)/(a[j].r2-a[j].r1);
    }
    if(a[i].r2>a[j].r2)
        return max(a[j].h-(a[j].r2-a[i].r1)/(a[i].r2-a[i].r1)*a[i].h,0.0);
    return max((a[i].r2-a[j].r1)/(a[j].r2-a[j].r1)*a[j].h-a[i].h,0.0);
}
int main ()
{
    int T,i,t,j,k,p;
    double sum=inf,res;
    cin>>n;
    for(i=1;i<=n;++i){
        cin>>a[i].h>>a[i].r1>>a[i].r2;
        id[i]=i;
    }
    do{
        res=0;
        for(i=1;i<=n;++i){
            f[i]=0;
            for(j=1;j<i;++j){
                f[i]=max(f[i],f[j]+solve(id[i],id[j]));
            }
            res=max(res,f[i]+a[id[i]].h);
        }
        sum=min(sum,res);
    }
    while(next_permutation(id+1,id+1+n));
    print(sum+0.5);

    return 0;
}
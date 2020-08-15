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
int n,m;
double dfs(double x, double y, int n)
{
    if(n==1)
        return x>y?x/y:y/x;
    double maxs=inf;
    for(int i=1;i<=n/2;++i){
        double x1=x*i/n, y1=y*i/n;
        maxs=min(maxs,max(dfs(x1,y,i),dfs(x-x1,y,n-i)));
        maxs=min(maxs,max(dfs(x,y1,i),dfs(x,y-y1,n-i)));
    }
    return maxs;
}
int main ()
{
    int T,x,y,i,t,j,k,p,sum=0;
    cin>>x>>y>>n;
    double maxs=dfs(x,y,n);
    printf("%.6f\n",maxs);
    
    return 0;
}
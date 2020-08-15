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
int n;
struct node
{
    double x,y;
};
node a[105];
double dp[105][105];
double triangle(node a, node b, node c)
{
    return fabs((a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x))/2;
}
bool judge(node d, node b, node c)
{
    double p=triangle(d,b,c);
    for(int i=1;i<=n;++i)
    {
        if((a[i].x==b.x &&a[i].y==b.y) ||(a[i].x==c.x &&a[i].y==c.y) ||(a[i].x==d.x &&a[i].y==d.y))
            continue;
        double s=triangle(d,b,a[i])+triangle(d,c,a[i])+triangle(b,c,a[i]);
        if(fabs(s-p)<1e-8)
            return false;
    }
    return true;

}
int main ()
{
    int T,m,i,t,j,k,p;
    while(cin>>n){
    for(i=1;i<=n;++i)
        cin>>a[i].x>>a[i].y;
    for(i=1;i<n-1;++i)
        dp[i][i+2]=triangle(a[i],a[i+1],a[i+2]);
    for(int l=4;l<=n;++l)
        for(i=1;i<=n-l+1;++i)
        {
            j=i+l-1;
            dp[i][j]=inf;
            for(k=i+1;k<j;k++)
                if(judge(a[i],a[j],a[k]))
                dp[i][j]=min(dp[i][j],max(triangle(a[i],a[j],a[k]),max(dp[i][k],dp[k][j])));
        }
    printf("%.1f\n",dp[1][n]);
    }
    return 0;
}
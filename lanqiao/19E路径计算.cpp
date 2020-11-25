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
int n,m,sum=0;
int res[10][10],dis[10][10];
int a[]={0,0,1,-1},b[]={1,-1,0,0};
void dfs(int x, int y,int sep)
{
    if(sep >12)
        return ;
    if(x==1 && y==1 &&sep<=12){
        sum++;
    }
    for(int i=0;i<4;++i){
        int j=x+a[i], k=y+b[i];
        if(j<1 || k<1 || j>6 ||k>6)
            continue;
        
        if(!dis[j][k]){
            dis[j][k]=1;
            dfs(j,k,sep+1);
            dis[j][k]=0;
        }
    }
}
int main ()
{
    int T,i,t,j,k,p;
    dfs(1,1,0);
    cout<<sum-3<<endl;
    
    return 0;
}
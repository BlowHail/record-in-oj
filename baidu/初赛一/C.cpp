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
int dp[1005][1005];

int judge(int a,int b)
{
    while(b!=0){
        int r=b;
        b=a%b; a=r;
    }
    if(a==1)
        return 1;
    else
        return 0; 
}

void init()
{
    dp[1][1]=1;
    for(int i=1;i<=1000;++i){
        for(int j=1;j<=1000;++j){
            if(i==1){
                dp[i][j]=dp[j][i]=j;
                continue;
            }
            if(dp[i][j]==0)
                dp[i][j]=dp[j][i]= max(dp[i-1][j],dp[i][j-1])+judge(i,j);
        }
    }
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    init();
    while(T--)
    {
        n=read();m=read();
        printf("%d\n",dp[n][m]);
        //p=judge(n,m);
        //cout<<"!"<<p<<endl;
    }
    
    return 0;
}
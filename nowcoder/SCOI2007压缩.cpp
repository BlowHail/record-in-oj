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
int dp[1005][1005][2];
string s;
int judge(int l,int r)
{
    int mid=(l+r)/2;
    for(int i=l;i<=mid;++i)
        if(s[i]!=s[mid+1+i-l])
            return 0;
    return 1;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>s;
    int len=s.length();
    dp[0][0][0]=1;
    for(int i=1;i<=len;++i){
        for(int l=0;l<len-i+1;++l){
            int r=l+i-1;
            dp[l][r][0]=i;dp[l][r][1]=i;
            for(int j=l;j<=r;++j){
                dp[l][r][0]=min(dp[l][j][0]+r-j,dp[l][r][0]);
                dp[l][r][1]=min(dp[l][r][1],min(dp[l][j][1],dp[l][j][0])+1+min(dp[j+1][r][1],dp[j+1][r][0]));
            }
            if(i%2==0 && judge(l,r) )
                dp[l][r][0]=min(dp[l][r][0],dp[l][(l+r)/2][0]+1);
        }
    }
    p=min(dp[0][len-1][0],dp[0][len-1][1]);
    cout<<p<<endl;
    
    return 0;
}
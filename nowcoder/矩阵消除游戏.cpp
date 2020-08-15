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
int n,m,a[30][30];
int times(int p)
{
    int sum=0;
    while(p){
        if(p&1)
            sum++;
        p>>=1;
    }
    return sum;
}
int main ()
{
    int T,i,t,j,k,p;
    ll sum=0,ans=0;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            cin>>a[i][j];
    
    for(i=0;i<(1<<n);i++){
        int num=times(i);
        if(num>k)
            continue;
        ll res=0,les[30];
        memset(les,0,sizeof(les));
        for(j=0;j<n;++j){
            for(t=1;t<=m;++t)
                if((i>>j)&1)
                    res+=a[j+1][t];
                else
                    les[t]+=a[j+1][t];
        }
        sort(les+1,les+1+m,greater<ll>());
        for(j=1;j<=k-num && j<=m ;j++)
            res+=les[j];
        ans=max(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}
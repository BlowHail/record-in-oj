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
int n,m,sum[100005];
int main ()
{
    int T,i,t,j,k,p;
    string s;
    T=read();
    while(T--)
    {
        n=read();
        cin>>s;
        s='0'+s;
        int l=n;
        sum[0]=0;
        sum[1]=s[0]-48;
        for(i=1;i<=l;++i){
            sum[i]=sum[i-1]+(s[i]-'0');
            //cout<<sum[i]<<endl;
        }
        int sums=0;
        for(i=1;i<=l;++i){
            for(int r=1,lo=r+i-1;lo<=l;++r,lo=r+i-1){
                p=sum[lo]-sum[r-1];
                if(p==lo-r+1)
                    sums++;
            }
        }
        printf("%d\n",sums);
    }
    
    return 0;
}
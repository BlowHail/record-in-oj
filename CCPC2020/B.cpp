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
string s;
int a[30];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    p=1;
    while(T--){
        cin>>s;
        memset(a,0,sizeof(a));
        int l=s.length();
        for(i=0;i<l;++i){
            a[ s[i]-97 ]++;
        }
        int maxs=0;
        for(i=0;i<27;++i)
            maxs=max(maxs,a[i]);
        printf("Case #%d: %d\n",p,maxs);
        p++;

    }
    
    return 0;
}
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
int judge(int n){
    for(int i=0;i<=n/3;++i){
        for(int j=0;j<=n/5;++j){
            for(int k=0;k<=n/7;++k){
                if(i*3+j*5+k*7==n){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                    return 1;
                }

            }
        }
    }
    return -1;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--){
        cin>>n;
        p=judge(n);
        if(p==-1)
            cout<<"-1"<<endl;
    }
    
    return 0;
}
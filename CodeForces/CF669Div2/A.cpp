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
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--){
        cin>>n;
        int sum0=0,sum1=0;
        for(i=1;i<=n;++i){
            cin>>k;
            if(k==0)
                sum0++;
            else
                sum1++;
        }
        if(sum0<sum1){
            k=sum1;
            if(k%2!=0)
                k--;
            printf("%d\n",k);
            for(i=1;i<k;++i)
                printf("1 ");
            printf("1\n");
        }
        else 
        {
            k=sum0;
            printf("%d\n",k);
            for(i=1;i<k;++i)
                printf("0 ");
            printf("0\n");
        }
    }
    
    return 0;
}
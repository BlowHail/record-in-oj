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
int a[105],res[11111];
int jiami(int k)
{
    if(res[k])
        return res[k];
    int sum=0;
    while(k){
        sum+=k%10;
        k/=10;
    }
    if(res[sum])
        return res[sum];
    if(sum>9)
        return  res[sum] = jiami(sum);
    return res[k] = sum;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>n;
    for(i=1;i<=n;++i){
        cin>>a[i];
        //cout<<a[i]<<endl;
    }
    p=1111;
    j=1;
    for(i=0;i<=p;++i){
        if( a[j]==jiami(i) )
            {
                //cout<<i<<" "<<a[j]<<endl;
                t=j;
                int f=1;
                for(int v=i+1;v<i+n;++v){
                    t++;
                    if(a[t]!=jiami(v)){
                        //cout<<a[t]<<" "<<jiami(v)<<endl;
                        f=0;
                        break;
                    }
                }
                if(f){
                    cout<<i<<" "<<i+n-1<<endl;
                    return 0;
                }
            }
    }
    cout<<"-1"<<endl;
    return 0;
}
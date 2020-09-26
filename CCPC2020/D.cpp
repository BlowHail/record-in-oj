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
int a[1000];
int pri(int p)
{
    int k=sqrt(p);
        for(int j=2;j<=k;++j)
            if(p%j==0)
                return 0;
    return 1;
}
int q;
void zhi()
{
    a[1]=2;a[2]=3;
    q=3;
    for(int i=4;i<=10;++i){
        if(pri(i))
            a[q]=i,q++;
    }
}
int main ()
{
    int T,i,t,k,p,sum=0;
    cin>>T;
    zhi();
    while(T--){
        sum=0;
        cin>>n;
        for(i=1;i<=n;++i){
            cin>>p;
            
            for(int j=1;j<=q;j++){
                //cout<<a[j]<<endl;
                if(a[j]>p)
                    break;
                if(p%a[j]==0 && p!=a[j]){
                    sum+=p/a[j];
                    break;
                }
            }
            sum++;
            //cout<<"!"<<endl;
        }
        if(sum%2==0)
            cout<<"L"<<endl;
        else 
            cout<<"W"<<endl;
    }
    
    return 0;
}
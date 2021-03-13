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
int a[10];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    string s;
    while(T--){
        cin>>s;
        
        t=s[0]-'0';
        if(s[1]=='i')
            ;
        else
            a[t]++;
    }
    int maxs=0,maxid=0;
    for(int i=1;i<=6;i++){
        if(maxs<a[i])
            maxs=a[i],maxid=i;
    }
    for(int i=1;i<=6;i++){
        if(a[i]==maxs&& maxs!=0)
            cout<<i<<" "<<maxs<<endl;
    }
    if(maxs==0)
        cout<<0<<" "<<maxs<<endl;
    
    return 0;
}
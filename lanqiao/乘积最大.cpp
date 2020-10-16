#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define mod 1000000009
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return f*x;
    
}
int n,k,a[100005];
int main ()
{
    n=read(); k=read();
    for(int i=0;i<n;++i){
        a[i]=read();
        if(a[i]<0)
            a[i]=-a[i];
    }
    sort(a,a+n,greater<int>());
    long long sum=1;
    for(int i=0;i<k;++i){
        sum*=a[i];
        sum%=mod;
    }
    
    cout<<sum<<endl;
    return 0;
}
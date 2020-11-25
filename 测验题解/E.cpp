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
int n,m;
int a[200005];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--){
        cin>>n;
        if(n==2)
        {
            cout<<"2"<<endl;
            cout<<"1"<<" "<<"2"<<endl;
            continue;
        }
    cout<<2<<endl;
    p=n-2;
    cout<<n<<" "<<p<<endl;
    for(int i=1;i<=n;++i)
        a[i]=i;
    a[n-2]=(n+n-2)/2;
    for(i=n-1;i>=2;i--){
        cout<<a[i]<<" "<<a[i-1]<<endl;
        a[i-1]=(a[i]+a[i-1])/2;
    }
    }
    return 0;
}

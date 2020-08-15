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
int n,m;
int a[30000005];
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>n;
    for(i=2;i<=n;++i)
    {
        if(!a[i]){
            sum+=i;
            for(j=i*i;j<=n;j+=i)
                if(!a[j])
                    sum+=i,a[j]=1;
        }
    }
    cout<<sum<<endl;
    return 0;
}
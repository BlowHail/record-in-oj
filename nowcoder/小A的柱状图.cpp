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
ll n,m,w[1000005],h[1000005];
int main ()
{
    ll T,i,t,j,k,p,sum=0;
    cin>>n;
    for(i=1;i<=n;++i){
        cin>>p;
        w[i]=w[i-1]+p;
    }
    for(i=1;i<=n;++i)
        cin>>h[i];
    h[n+1]=0;
    stack<ll> s;
    s.push(0);
    for(i=1;i<=n;++i){
        if(h[i]>=h[s.top()]||s.empty())
            s.push(i);
        else{
            while(!s.empty()&&h[i]<h[s.top()]){
                int l=s.top();
                s.pop();
                sum=max(sum,(w[i-1]-w[s.top()])*h[l]);
            }
            s.push(i);
        }
    }
    cout<<sum<<endl;
    
    return 0;
}
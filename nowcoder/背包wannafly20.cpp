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
struct node
{
    ll a,b;
}a[100005];
bool cmp(node x, node y)
{
    return x.a<y.a;
}
priority_queue<ll>q;
ll sum1[100005],sum2[100005];
int main ()
{
    ll T,n,m,i,t,j,k,v,p;
    cin>>v>>n>>m;
    for(i=1;i<=n;++i)
        scanf("%lld %lld",&a[i].a,&a[i].b);
    sort(a+1,a+1+n,cmp);
    k=m/2+(m&1);
    //cout<<k<<"!";
    for(i=1;i<=n;++i)
    {
        q.push(a[i].b);
        sum1[i]=sum1[i-1]+a[i].b;
        if(q.size()>k-1)
            sum1[i]-=q.top(),q.pop();
    }
    while (!q.empty())
        q.pop();
    
    for(i=n;i>0;--i)
    {
        q.push(a[i].b);
        sum2[i]+=sum2[i+1]+a[i].b;
        if(q.size()>k-1)
            sum2[i]-=q.top(),q.pop();
    }
    
    if(m&1)
    {
        ll res=0;
        for(i=k;i<=n-m/2;++i)
            if(sum1[i-1]+sum2[i+1]+a[i].b<=v)
                res=a[i].a;
        cout<<res<<endl;
    }
    else
    {
        ll res=0;
        for(i=k;i<=n-m/2;++i)
        {
            int l=i+1,r=n-m/2+1;
            while (l<=r)
            {
                ll mid=(l+r)/2;
                if(sum1[i-1]+sum2[mid+1]+a[i].b+a[mid].b<=v)
                    l=mid+1;
                else 
                    r=mid-1;
            }
            if(r>i)
                res=max(res,a[i].a+a[r].a);
        }
        cout<<res/2<<endl;
    }
    
    
    return 0;
}
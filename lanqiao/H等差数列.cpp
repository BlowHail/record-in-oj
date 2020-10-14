#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
ll a[1000005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    ll cha=inf;
    for(int i=1;i<n;++i){
        cha=min(cha,a[i]-a[i-1]);
    }
    if(cha==0){
        cout<<n<<endl;
        return 0;
    }
    ll p=(a[n-1]-a[0])/cha+1;
    cout<<p<<endl;
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int a[100005],b[100005],c[100005];
int main ()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&c[i]);
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    long long  j,k;
    long long sum=0;
    for(int i=0;i<n;++i){
        j=lower_bound(a,a+n,b[i])-a;
        k=upper_bound(c,c+n,b[i])-c;
        k=n-k;
        sum+=j*k;
        //cout<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
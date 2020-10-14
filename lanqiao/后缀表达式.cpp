#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[200005];
bool cmp(int x, int y)
{
    return x>y;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int p=n+m+1,j=0,k=0;
    for(int i=1;i<=p;++i){
        scanf("%d",&a[i]);
        if(a[i]<0)
            j++;
    }
    sort(a+1,a+1+p);
    long long sum=0;
    if(j<m){
        sum-=a[1];
        for(int i=2;i<=p;++i){
            if(a[i]<0)
                sum-=a[i];
            else 
                sum+=a[i];
        }
    }
    else if (m<=j && m>0){
        sum+=a[p];
        for(int i=1;i<p;++i){
            if(a[i]<0)
                sum-=a[i];
            else 
                sum+=a[i];
        }
    }
    else{
        for(int i=1;i<=p;++i)
            sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}
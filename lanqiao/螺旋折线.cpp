#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
int main ()
{
    ll x,y,sum=0;
    cin>>x>>y;
    
    ll j=fabs(x),k=fabs(y);
    ll p=max(j,k)-1;
    sum=p*(1+p)*4;
    p++;
    if(x+p==0 || (y+p)/(x+p)>=1){
        sum+=y+p+x+p;
    }
    else 
        sum+=p*8-(y+p+x+p);
    cout<<sum<<endl;
    return 0;
}
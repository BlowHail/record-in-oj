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
int lcm(int k)
{
    int p=sqrt(k);
    for(int i=2;i<=p;++i)
    {
        if(k%i==0)
            return i;
    }
    return 1;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while (T--)
    {
        cin>>n;
        p=lcm(n);
        if(p==1)
            cout<<p<<" "<<n-p<<endl;
        else 
            {
                p=n/p;
                cout<<p<<" "<<n-p<<endl;
            }
        /* code */
    }
    
    
    return 0;
}
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
ll n,m;
int main ()
{
    ll T,i,t,j,k,p,sum=0,a,b;
    cin>>T;
    while (T--)
    {
        cin>>a>>b>>n>>m;
        p=abs(a-b);
        k=min(a,b);
        n-=p;
        if(n<0)
        {
            if(k<m)
                cout<<"No"<<endl;
            else 
                cout<<"Yes"<<endl;
        }
        else 
        {
            j=min(n,m);
            k-=j;

            if(n<m)
            {
                if(m-n>k)
                    cout<<"No"<<endl;
                else 
                    cout<<"Yes"<<endl;
                
            }
            else 
            {
                if(n-m>2*k)
                    cout<<"No"<<endl;
                else 
                    cout<<"Yes"<<endl;
            }
            
        }
        /* code */
    }
    
    
    return 0;
}
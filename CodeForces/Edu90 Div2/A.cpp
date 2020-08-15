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
int main ()
{
    int T,i,t,j,k,p,sum=0,a,b,c;
    cin>>t;
    while (t--)
    {
        cin>>a>>b>>c;
        if(a>=c)
            cout<<"-1 ";
        else if(a<c)
            cout<<"1 ";
        if(c/b>=a)
            cout<<"-1"<<endl;
        else
            cout<<b<<endl;

        /* code */
    }
    
    
    return 0;
}
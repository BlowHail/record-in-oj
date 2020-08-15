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
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while (T--)
    {
        cin>>n;
        int f=1,b1,bn,d=inf,f2=1;
        for(i=1;i<=n;++i)
        {
            scanf("%d",&k);
            if(i!=k&&f)
            {
                f=0;b1=i;
            }
            if(!f &&i!=k)
                bn=i;
            if(!f && i==k &&f2)
                d=i,f2=0;
        }
        if(f)
            cout<<"0"<<endl;
        else 
        {
            if(d<bn &&!f2)
                cout<<"2"<<endl;
            else 
                cout<<"1"<<endl;
        }
        /* code */
    }
    
    
    return 0;
}
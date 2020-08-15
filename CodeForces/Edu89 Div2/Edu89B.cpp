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
int main ()
{
    int T,n,m,i,t,j,k,p,x;
    int mins=0,maxs=inf;
    cin>>T;
    while (T--)
    {
        cin>>n>>x>>m;
        mins=inf; maxs=0;
        for(i=0;i<m;++i)
        {
            cin>>j>>k;
            if(x>=j && x<=k)
            {
                mins=min(mins,j);
                maxs=max(maxs,k);
            }
            else
            {
                if(k>=mins && j<=mins)
                    mins=min(mins,j),maxs=max(maxs,k);
                if(j<=maxs && k>=maxs)
                    maxs=max(maxs,k),mins=min(mins,j);
            }
        }
        p=maxs-mins;
        if(p<0)
            p=0;
        p++;
        cout<<p<<endl;
    }
    
    
    return 0;
}
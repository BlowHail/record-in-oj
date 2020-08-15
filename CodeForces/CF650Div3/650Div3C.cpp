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
int a[200005];
string s;
int main ()
{
    int T,n,m,i,t,j,k,p;
    cin>>T;
    while (T--)
    {
        /* code */
        cin>>n>>k;
        cin>>s;
        p=1;
        for(i=0;i<n;++i)
            if(s[i]=='1')
            {
                a[p++]=i+1;
            }
        a[0]=-k; a[p]=n+1+k;

        int sum=0;
        for(i=1;i<=p;++i)
            {
                j=a[i];
                while (j>a[i-1])
                {
                    j-=k+1;
                    if(j>a[i-1]+k)
                        sum++;
                    //cout<<j<<endl;
                }
            }
        
        
        cout<<sum<<endl;

    }
    
    
    return 0;
}
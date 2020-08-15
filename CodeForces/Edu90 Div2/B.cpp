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
    cin>>t;
    string s;
    while (t--)
    {
        cin>>s;
        k=s.length();
        j=0;p=0;
        for(i=0;i<k;++i)
            if(s[i]=='0')
                j++;
            else 
                p++;
        //cout<<j<<p;
        j=min(j,p);
        if(j%2==0)
            cout<<"NET"<<endl;
        else
        {
            cout<<"DA"<<endl;
        }
        
        /* code */
    }
    
    
    return 0;
}
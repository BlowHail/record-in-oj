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
    int T,n,m,i,t,j,k,p;
    string s,b;
    cin>>n;
    while (n--)
    {
        cin>>s;
        int l=s.length();
        for(i=0;i<l;i+=2)
            cout<<s[i];
        if(l%2==0)
            cout<<s[l-1]<<endl;
        else
        {
            cout<<endl;
        }
        
    }
    
    
    return 0;
}
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
string s;
int a[100005];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cin>>s;
        j=-1; k=-1;
        p=0;
        memset(a,0,sizeof(a));
        for(i=0;i<n;++i)
            if(s[i]=='1' && k==-1)
                k=0;
            else if (s[i]=='0' && k>=0)
                k++,a[i]=1;
            
        for(i=n-1;i>=0;i--)
            if(s[i]=='0' &&j==-1)
                j=0,p=i;
            else if (s[i]=='1' &&j>=0)
                j++,a[i]=1;
        a[p]=0;
        for(i=0;i<n;++i)
            if(a[i]==0)
            cout<<s[i];
        cout<<endl;
        
            
        /* code */
    }
    
    
    return 0;
}
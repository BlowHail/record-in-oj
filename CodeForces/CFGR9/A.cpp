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
int a[105];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while (T--)
    {
        cin>>n;
        for(i=1;i<=n;++i){
            cin>>a[i];
            if(i%2==0){
                if(a[i]<0)
                    a[i]=-a[i];}
            else if(a[i]>0)
                a[i]=-a[i];
        }
        for(i=1;i<=n;++i)
            cout<<a[i]<<" ";
        cout<<endl;
        /* code */
    }
    
    
    return 0;
}
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
    cin>>T;
    while (T--)
    {
        cin>>n;
        j=0;k=0;
        for(i=0;i<n;++i){
            cin>>t;
            
            if( (t%2==1) && (i%2==0))
                j++;
            else if((t%2==0) &&(i%2==1))
                k++;
        }
            if(j==k)
                cout<<j<<endl;
            else 
                cout<<"-1"<<endl;
  
        
    }
    
    
    return 0;
}
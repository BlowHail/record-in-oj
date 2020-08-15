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
int a[1000005],b[100005];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while (T--)
    {
        cin>>n;
        b[0]=inf;
        for(i=1;i<=n;++i){
            cin>>a[i];
            if(a[i]<b[i-1])
                b[i]=a[i];
            else 
                b[i]=b[i-1];
        }
        //去
        int f=0;
        for(i=2;i<=n;++i)
        {
            if(a[i]>b[i-1])
            {
                for(t=i+1;t<=n;++t)
                    if(a[t]<a[i]){
                        f=1;
                        cout<<"YES"<<endl;
                        p=b[i-1];
                        for(int j=1;j<i;++j)
                            if(a[j]==p){
                                cout<<j<<" ";
                                break;
                            }
                        cout<<i<<" "<<t<<endl;
                        break;
                    }
                if(f)
                break;
            }
        }
        if(!f)
            cout<<"NO"<<endl;
    }
    return 0;
}
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
int n,m,a[10005],ans[10005];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>n;
    p=1;
    for(i=2;i<=n;++i){
        cout<<"?"<<" "<<p<<" "<<i<<endl;
        fflush(stdout);
        cin>>j;

        cout<<"?"<<" "<<i<<" "<<p<<endl;
        fflush(stdout);
        cin>>k;

        if(j>k){
            a[j]=1;
            ans[p]=j;
            p=i;
        }
        else{
            a[k]=1;
            ans[i]=k;
        }
    }
    cout<<"!"<<" ";
    for(i=1;i<=n;++i){
        if(ans[i])
            cout<<ans[i]<<" ";
        else{
            for(int v=1;v<=n;++v)
                if(a[v]==0){
                    cout<<v<<" ";
                    break;
                }
        }
    }
    return 0;
}
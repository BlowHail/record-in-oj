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
int n,m,k,p,vis[200005],res[55][200005],s[200005],z[200005];
int main ()
{
    int T,i,t,j;
    cin>>n>>k>>p;
    for(i=1;i<=n;++i){
        cin>>s[i]>>z[i];
        if(z[i]<=p)
            vis[i]=i;
        else 
            vis[i]=vis[i-1];
        
        res[s[i]][i]++;
        for(int v=0;v<k;++v)
            res[v][i]+=res[v][i-1];
    }
    ll sum=0;
    for(i=2;i<=n;++i){
        sum+=res[s[i]][vis[i]];
        if(z[i]<=p)
            sum--;
    }
    cout<<sum<<endl;
    return 0;
}
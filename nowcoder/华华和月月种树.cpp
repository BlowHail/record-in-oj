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
int n,m,cnt=1,tot,a[400005],b[400005],c[400005],o[400005],in[400005],out[400005],vis[400005];
vector<int> e[400005];
void dfs(int x)
{
    in[x]=++tot;
    for(int i=0;i<e[x].size();++i)
        dfs(e[x][i]);
    out[x]=tot;
}
int lowbit(int x)
{
    return x&(-x);
}
void add(int x, int v)
{
    while (x<=cnt){
        c[x]+=v;
        x+=lowbit(x);
    }
}
int getsum(int x)
{
    int res=0;
    while (x>0){
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>m;
    for(i=1;i<=m;++i){
        cin>>o[i]>>a[i];
        a[i]++;
        if(o[i]==1){
            e[a[i]].push_back(++cnt);
            b[i]=cnt;
        }
        if(o[i]==2)
            cin>>b[i];
    }
    dfs(1);
    for(i=1;i<=m;++i){
        if(o[i]==1)
            vis[in[b[i]]]-=getsum(in[a[i]]);
        else if(o[i]==2){
            add(in[a[i]],b[i]);
            add(out[a[i]]+1,-b[i]);
        }
        else 
            cout<<vis[in[a[i]]]+getsum(in[a[i]])<<endl;
    }
    
    return 0;
}
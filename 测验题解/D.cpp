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
#define _int __int128_t
int r,c,ans,cost[45][45],vis[45][45];
struct node
{
    int x,y,res;
};
queue <node> q;
void bfs()
{
    node p;
    p.x=1;p.y=1;p.res=1;
    q.push(p);
    int x[]={1,-1,0,0},y[]={0,0,1,-1};
    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p.x==r && p.y==c){
            ans=p.res;
            return ;
        }
        for(int i=0;i<4;i++){
            node k;
            k.x=p.x+x[i],k.y=p.y+y[i],k.res=p.res+1;
            if(cost[k.x][k.y]==1 && vis[k.x][k.y]==0){
                vis[k.x][k.y]=1;
                q.push(k);
            }
        }
    }
}
int main ()
{
    cin>>r>>c;
    char s;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;++j){
            cin>>s;
            if(s=='.')
                cost[i][j]=1;
        }
    bfs();
    cout<<ans<<endl;
    
    return 0;
}
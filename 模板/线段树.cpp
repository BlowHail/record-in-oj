
//题目大意： 有n天可以租教室，给出每天可以租用的教室数量，有m次询问，找出最小值判断能不能完成租借。
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
int a[1000005];
struct node{
    int l,r,min,f;
}tree[4000005];
void build(int i, int l, int r)  //建树
{
    tree[i].l=l,tree[i].r=r;
    if(l==r)
    {
        tree[i].min=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    tree[i].min=min(tree[i<<1].min,tree[i<<1|1].min);
}
void down(int i) //懒节点下穿
{
    tree[i<<1].f+=tree[i].f;
    tree[i<<1|1].f+=tree[i].f;
    tree[i<<1].min-=tree[i].f;
    tree[i<<1|1].min-=tree[i].f;
    tree[i].f=0;
}
void add(int p, int j, int k, int i) //维护区间
{
    if(tree[i].l>=j &&tree[i].r<=k)
    {
        tree[i].min-=p;
        tree[i].f+=p;
        return ;
    }
    if(tree[i].f)
        down(i);
    if(tree[i<<1].r>=j)
        add(p,j,k,i<<1);
    if(tree[i<<1|1].l<=k)
        add(p,j,k,i<<1|1);
    tree[i].min=min(tree[i<<1].min,tree[i<<1|1].min);
}
int mins=inf;
void ask(int j, int k, int i) //找区间最小值
{
    if(tree[i].l>=j && tree[i].r<=k)
    {
        mins=min(mins,tree[i].min);
        return ;
    }
    if(tree[i].f)
        down(i);
    if(tree[i<<1].r>=j)
        ask(j,k,i<<1);
    if(tree[i<<1|1].l<=k)
        ask(j,k,i<<1|1);
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    for(i=0;i<m;++i)
    {
        scanf("%d %d %d",&p,&j,&k); 
        mins=inf;
        ask(j,k,1);
        if(mins<p){
            cout<<"-1"<<endl<<i+1<<endl;
            return 0;
        }
        add(p,j,k,1);
    }
    cout<<"0"<<endl;
    return 0;
}
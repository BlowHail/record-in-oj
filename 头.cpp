#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<1)+(x<<3)+c-'0',c=getchar();
}
int dis[100005],sign[100005],cost[1005][1005];
void dij(int n)
{
    dis[0]=0;
    while (1)
    {
        int f=-1;
        for(int i=0;i<n;++i)
            if(!sign[i]&&(f==-1 || dis[i]<dis[f]))
                f=i;
        if(f==-1)
            break;
        sign[f]=1;
        for(int i=0;i<n;++i)
            dis[i]=min(dis[i],dis[f]+cost[f][i]);
        /* code */
    }
    
}
int fat[10005];
int find(int a)
{
    if(fat[a]==a)
        return a;
    return fat[a]=find(fat[a]);
}
void join(int a, int b)
{
    int j=find(a),k=find(b);
    fat[j]=k;
}

int lowbit(int i)
{
    return i&(-i);
}
int n,c[10005];
void add(int i, int k)
{
    while(i<=n){
        c[i]+=k;
        i+=lowbit(i);
    }
}
int getsum(int i)
{
    int res=0;
    while(i>0){
        res+=c[i];
        i-=lowbit(i);
    }
}
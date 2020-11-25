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
int n,m,fat[100005],edge=0,num[100005];
int find(int x)
{
    if(fat[x]==x)
        return x;
    return fat[x]=find(fat[x]);
}
void join(int a, int b)
{
    int j=fat[a],k=fat[b];
    fat[j]=k;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    for(int i=1;i<=100000;i++)
        fat[i]=i;
    int f=1;
    while(scanf("%d %d",&j,&k) && j!=-1 &&k!=-1){
        edge++;
        if(num[j]==0)
            num[j]=1,sum++;
        if(num[k]==0)
            num[k]=1,sum++;
        if(j==0 && k==0){
            if(f && (sum-edge==1 || sum==1) )
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
            for(int i=1;i<=100000;i++)
                fat[i]=i;
            f=1; edge=0; sum=0;
            memset(num,0,sizeof(num));
            continue;
        }
        int x=find(j),y=find(k);
        if(x==y)
            f=0;
        join(j,k);
    }
    
    return 0;
}

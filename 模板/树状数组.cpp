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
int n,a[200005],c[200005];
struct node{
    int x,y,z;
}tr[200005];
bool rankx (node x ,node y) ///�Ե�һ����������
{
    return x.x<y.x;
}
bool ranky (node x,node y) ///�Եڶ�����������
{
    return x.y<y.y;
}

int lowbit(int i)
{
    return i&-i;
}
void add(int i, int k) 
{
    while(i<=n)
    {
        c[i]+=k;
        i+=lowbit(i);
    }
}
int getsum(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}

int main ()
{
    int m,i,t,j,k,p=1;
    ll sum=0;
    cin>>n;
    for(i=1;i<=n;++i)
        scanf("%d %d %d",&tr[i].x,&tr[i].y,&tr[i].z);
    ///��һ���ȶԵ�һ����������
    sort(tr+1,tr+n+1,rankx);
    for(i=1;i<=n;++i){
        add(tr[i].y,1);
        sum+=i-getsum(tr[i].y);  ///��ڶ����������
    }
    memset(c,0,sizeof(c)); ///����һ��
    for(i=1;i<=n;++i){
        add(tr[i].z,1);
        sum+=i-getsum(tr[i].z);///����������������
    }
    ///���յڶ�����������Ȼ����������������
    sort(tr+1,tr+n+1,ranky);
    memset(c,0,sizeof(c));
    for(i=1;i<=n;++i){
        add(tr[i].z,1);
        sum+=i-getsum(tr[i].z); 
    }

    cout<<sum/2<<endl;

    return 0;
}
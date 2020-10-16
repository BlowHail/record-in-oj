#include <bits/stdc++.h>
#include <iostream>
#define ll long long 
using namespace std;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')  f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')   x=(x<<1)+(x<<3)+c-'0' , c=getchar();
    return f*x;
}
struct node{
    int ts,id;
}a[100005];
bool cmp(node x, node y){
    return x.ts<y.ts;
}
int id[100005],mark[100005];
int main ()
{
    int n=read(),d=read(),k=read();
    for(int i=1;i<=n;++i)
        a[i].ts=read(),a[i].id=read();
    sort(a+1,a+1+n,cmp);
    int i=1;
    for(int j=1;j<=n;++j){
        while(a[j].ts>=a[i].ts+d){
            id[a[i].id]--;
            i++;
        }
        id[a[j].id]++;
        if(id[a[j].id]>=k){
            mark[a[j].id]=1;
        }
    }
    for(int i=0;i<=100000;++i)
        if(mark[i])
            printf("%d\n",i);

    return 0;
}
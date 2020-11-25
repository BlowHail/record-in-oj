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
using namespace std;
int fat[30005];
int finds(int n)
{   //查找
    if(fat[n]==n)
        return n;
    return fat[n]=finds(fat[n]);  //路径压缩
}
void join(int a, int b)
{   //合并
    int j=finds(a), k=finds(b);
    if(j<k)
        fat[k]=j;
    else
        fat[j]=k;
}
int main ()
{
    int n,m,i,t,j,k,n2,a,b;
    while(scanf("%d %d",&n,&m)&&n+m)
    {
        for(i=0;i<n;++i)
            fat[i]=i;
        while(m--)
        {
            scanf("%d %d",&n2,&a);
            for(i=1;i<n2;++i){
                scanf("%d",&b);
                join(a,b);
            }
        }
        int sum=0;
        for(i=0;i<n;++i)
            if(finds(i)==0)
            sum++;
        printf("%d\n",sum);
    }
    return 0;
}
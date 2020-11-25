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
int dis[100005],b[100005];
int main ()
{
    int n,sum,k;
    while(cin>>n){
        for(int i=0;i<n;++i)
            cin>>dis[i];
        memset(b,0,sizeof(b));
        b[0]=dis[0];
        int p=0;
        for(int i=0;i<n;++i)
            if(dis[i]>b[p])
                b[++p]=dis[i];
            else{
                int k=upper_bound(b,b+p,dis[i])-b;
                b[k]=dis[i];
            }
        cout<<p+1<<endl;
    }
    return 0;

int b[100],a[100],len,i,t;

//用数组b来记录这个最长的子序列
//a是输入的序列
b[1]=a[1]; 
len =1;
    for (i=2;i<=n;++i)
    {
        if (a[i]>=b[len])   //如果a[i]大于b的末尾元素直接在b后面加上a[i]
            b[++len]=a[i];
        else
        {
            t=upper_bound( b+1 , b+len+1 , a[i] )-b; //寻找b数组中第一个大于a[i]的下标
            b[t]=a[i];
        }
    }
//最后len的长度即为最长的子序列长度

}
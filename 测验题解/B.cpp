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
int n,m;
int main ()
{
    cin>>n;
    m=n/2+1;
    cout<<m<<endl; //根据规律，直接算出棋盘大小
    for(int i=1;i<=m;++i)
        printf("%d %d\n",1,i);
    for(int i=2;i<=n-m+1;++i)
        printf("%d %d\n",i,m);
    
    return 0;
}

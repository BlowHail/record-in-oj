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
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return f*x;
}
void print(int x)
{
    if(x < 0) {putchar('-');x = -x;}
    if(x/10) print(x/10);
    putchar(x%10+'0');
}
int n,m;
int num[305];
int main ()
{
    ll sum=0;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>num[i];
    n++; num[n]=0;
    sort(num,num+n,greater<int>());
    int f=n/2;
    //cout<<f<<endl;
    int p=n-1;
    for (int i = 0; i < f; i++)
    {
        sum+=(num[i]-num[p])*(num[i]-num[p])+(num[i]-num[p-1])*(num[i]-num[p-1]);
        p--;
        /* code */
    }
    cout<<sum<<endl;

    return 0;
}
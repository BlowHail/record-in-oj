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
int n,m,a[200005];
string s,s2;
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>n;
    cin>>s;

    s2=s;
    p=n-1;
    //reverse(s2.begin(),s.end());
    for(i=0;i<n;++i)
        s2[p--]=s[i];

    sum=0;
    for(i=0;i<n;++i){
            for(j=0;j<n;++j){
                if(s2[j]==s[i]){
                    s2[j]='0';
                    p=j+a[j];
                    break;
                }
                a[j]++;
            }
            sum+=p-i;
    }
    cout<<sum<<endl;

    return 0;
}
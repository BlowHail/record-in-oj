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
int n,m,a[105];
bool cmp(int x, int y)
{
    return x>y;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    string s;
    cin>>T;
    while(T--){
        cin>>s;
        int l=s.length();
        k=0;
        for(i=0;i<l;++i){
            p=i;
            if(s[i]=='0')
                continue;
            while(s[i]==s[i+1])
            {
                i++;
            }
            p=i-p+1;
            a[k]=p;
            //cout<<a[k]<<"!"<<i<<endl;
            k++;
        }
        sum=0;
        sort(a,a+k,cmp);
        for(i=0;i<k;i+=2)
            sum+=a[i];
        cout<<sum<<endl;
    }
    
    return 0;
}
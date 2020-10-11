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
int a[200006];
string s;
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--){
        cin>>n;
        cin>>s;
        p=1;
        memset(a,0,sizeof(a));
        for(i=0;i<n;++i){
            a[p]++;
            if(s[i]!=s[i+1])
                p++;
        }
        int sum=0;
        for(i=1;i<p;++i){
            int f=0;
            for(j=i;j<p;++j){
                if(a[j]>1){
                    a[j]--;
                    f=1;
                    sum++;
                    break;
                }
            }
            if(!f){
                sum+= (p-i);
                break;
            }
            sum++;
        }
        if(sum%2!=0)
            sum++;
        sum/=2;
        cout<<sum<<endl;
    }
    
    return 0;
}
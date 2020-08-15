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
string s;
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while(T--){
        cin>>n>>s;
        sum=0;
        int res=0;
        for(i=0;i<n-6;++i){
            if(s[i]==s[i+2]==s[i+4]==s[i+6]=='a' && s[i+1]==s[i+5]=='b' &&s[i+3]=='c')
                sum++;
            if( (s[i]=='a'||s[i]=='?') && (s[i+2]=='a'||s[i+2]=='?')&&
                 (s[i+4]=='a'||s[i+4]=='?') && (s[i+6]=='a'||s[i+6]=='?') &&
                 s[i+1]=='b'&& s[i+5]=='b' &&s[i+3]=='c')
                 ;
        }
    }
    
    return 0;
}
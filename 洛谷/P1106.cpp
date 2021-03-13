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
    int k,l;
    cin>>s;
    cin>>k;
    
    string s4;
    int f=1;
    for(int i=0;i<s.length();i++){
        if(!f)
            s4+=s[i];
        if(s[i]!='0' &&f)
            s4+=s[i],f=0;
    }
    l=s4.length();
    s=s4;
    while (k--)
    {
        int maxs=0,mark=0,flag=0;
        for(int i=0;i<l;i++){
            if(s[i]>='0' &&s[i]<='9'){
                if((s[i]-'0')>=maxs ){
                    mark=i,maxs=s[i]-'0' ;
                //cout<<mark<<" "<<s[i]<<endl;
                }
                flag++;
            }
            if(flag>2)
                break;
        }
        //cout<<mark<<endl;
        s[mark]='.';
        /* code */
    }
    string s2;
    for(int i=0;i<l;i++)
        if(s[i]>='0' &&s[i]<='9')
            s2+=s[i];
    string s3;
    f=1;
    for(int i=0;i<s2.length();i++){
        if(!f)
            s3+=s2[i];
        if(s2[i]!='0' &&f)
            s3+=s2[i],f=0;
    }
    if(s3.length()<1)
        s3+='0';
    cout<<s3<<endl;
    return 0;
}
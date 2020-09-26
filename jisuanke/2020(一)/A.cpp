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
string s[30];
int judge(int x, int y,char p)
{
    int j,k;
    j=x,k=y;
    //cout<<"!!";
    //横着
    for(int i=0;i<=4;i++){
        j=x-i;
        if(j<0||j>24 ||k<0 ||k>24)
            continue;
        int sum=0;
        if(s[x][y]==p)
            sum--;
        j--;
        for(int u=0;u<=4;++u){
            j++;
            if(j<0||j>24 ||k<0 ||k>24)
            continue;
            if(s[j][k]==p)
                sum++;
        }
        if(sum>=4)
            return 1;
    }
    j=x,k=y;
    //shuzhe
    for(int i=0;i<=4;i++){
        k=y-i;
        if(j<0||j>24 ||k<0 ||k>24)
            continue;
        int sum=0;
        if(s[x][y]==p)
            sum--;
            k--;
        for(int u=0;u<=4;++u){
            k++;
            if(j<0||j>24 ||k<0 ||k>24)
            continue;
            if(s[j][k]==p)
                sum++;
        }
        if(sum>=4)
            return 1;
    }
    j=x,k=y;
    //youxia
    for(int i=0;i<=4;i++){
        k=y+i;
        j=x-i;
        if(j<0||j>24 ||k<0 ||k>24)
            continue;
        int sum=0;
        if(s[x][y]==p)
            sum--;
        k++;
        j--;
        for(int u=0;u<=4;++u){
            k--;
            j++;
            if(j<0||j>24 ||k<0 ||k>24)
            continue;
            if(s[j][k]==p)
                sum++;
        }
        if(sum>=4)
            return 1;
    }
    j=x,k=y;
    //youshang
    for(int i=0;i<=4;i++){
        k=y-i;
        j=x-i;
        if(j<0||j>24 ||k<0 ||k>24)
            continue;
        int sum=0;
        if(s[x][y]==p)
            sum--;
        k--; j++;
        for(int u=0;u<=4;++u){
            k++;
            j++;
            if(j<0||j>24 ||k<0 ||k>24)
            continue;
            if(s[j][k]==p)
                sum++;
        }
        if(sum>=4)
            return 1;
    }
    return 0;
}
int main ()
{
    int T,i,t,j,k,sum=0;
    for(i=0;i<25;++i)
        cin>>s[i];
    j=0;k=0;
    for(i=0;i<25;++i){
        for(int u=0;u<25;++u)
            if(s[i][u]=='o')
                j++;
            else if (s[i][u]=='x')
                k++;
    }
    char p;
    //cout<<j<<" "<<k;
    if(j+k==25*25){
        cout<<"tie"<<endl;
        return 0;
    }
    if(j==k)
        p='x';
    else p='o';
    //cout<<p<<endl;
    int f=0;
    for(i=0;i<25;++i){
        for(int u=0;u<25;++u)
            if(judge(i,u,p)){
                cout<<i<<" "<<u<<endl;
                f=1;
            }
    }
    if(!f)
        cout<<"tie"<<endl;
    
    return 0;



}

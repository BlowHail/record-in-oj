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
using namespace std;
#define _int __int128_t
inline ll read()
{
    ll x=0,f=1;
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
ll n,mod;
struct Matrix {
    ll a[5][5];
    Matrix() { memset(a, 0, sizeof a); } // 构造函数，矩阵初始化全零
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        for (int i = 1; i <= 4; ++i)
            for (int j = 1; j <= 4; ++j)
                for (int k = 1; k <= 4; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
        return res;
    }
} ans, base;
void qpow(int b) {
    while (b) {
        if (b & 1) ans = ans * base;
        base = base * base;
        b >>= 1;
    }
}
int main ()
{
    int T,i,t,j,k,p;
    cin>>T;
    while (T--)
    {
        n=read(); mod=read();
        if(n==1) printf("%d\n",1);
        else if(n==2) printf("%d\n",5);
        else if(n==3) printf("%d\n",11);
        else if(n==4) printf("%d\n",36);
        else{
            base.a[1][1]=1,base.a[1][2]=1,base.a[2][3]=1,base.a[3][1]=1,base.a[3][4]=1;
            base.a[2][1]=5;
            base.a[4][1]=-1;
            base.a[1][3]=0,base.a[1][4]=0,base.a[2][2]=0,base.a[2][4]=0,base.a[3][2]=0;
            base.a[3][3]=0,base.a[4][2]=0,base.a[4][3]=0,base.a[4][4]=0;
            ans.a[1][4]=1; ans.a[1][3]=5; ans.a[1][2]=11; ans.a[1][1]=36;
            qpow(n-4);
            printf("%lld\n",(ans.a[1][1]%mod+mod)%mod);
        }
    }
    return 0;
}
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
    int T,i,t,j,k,p,sum=0;
    cin>>n;
    for(int i=1;i<=1000000;i++){
        sum=0;
        for(int j=1;j<=i;++j){
            if(i%j==0)
                sum++;
            if(sum==n){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    
    return 0;
}
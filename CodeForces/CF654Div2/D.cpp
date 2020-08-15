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
int n,m;
int a[305][305];
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>T;
    while (T--)
    {
        memset(a,0,sizeof(a));
        cin>>n>>k;
        t=1;
        while (k)
        {
            for(i=t;i<=n;++i){  //放置左下的区域 
                if(a[i][i-t+1]==0 &&k)
                    a[i][i-t+1]=1,k--;
            }
            for(j=1;j<t;++j) //放置右上角的区域
                if(a[j][n-t+j+1]==0 &&k)
                    a[j][n-t+j+1]=1,k--;
            t++;
        }
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                a[0][j]+=a[i][j],a[i][0]+=a[i][j];  //计算行与列的和
        int rmax=0,rmin=n,cmax=0,cmin=n;
        for(i=1;i<=n;++i) //找出最大值和最小值
            rmax=max(rmax,a[0][i]),rmin=min(rmin,a[0][i]),
            cmax=max(cmax,a[i][0]),cmin=min(cmin,a[i][0]);
        sum=(rmax-rmin)*(rmax-rmin)+(cmax-cmin)*(cmax-cmin);
        cout<<sum<<endl;
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j)
                cout<<a[i][j];
                cout<<endl;
        
        }
    }
    return 0;
}
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
struct node
{
    int a,b;
}a[55],b[55];
string s;
int aa[55],out[55];
int main ()
{
    int T,n,m,i,t,j,k,p;
    cin>>T;
    while (T--)
    {
        cin>>s;
        p=s.length();
        cin>>n;
        for(i=0;i<n;++i)
            {
                cin>>a[i].a;
                a[i].b=0;
            }
        memset(aa,0,sizeof(aa));
        memset(out,0,sizeof(out));
        for(i=0;i<p;++i)
            aa[s[i]-96]++;
        p=26;
        while(p)
        {
            //cout<<"!!"<<endl;
            int cnt=0;
            for(i=0;i<n;++i)
                if(a[i].a==0&&a[i].b==0)
                    cnt++;
            for(i=p;i>=1;i--)
                if(aa[i]>=cnt)
                {
                    p=i-1;
                    break;
                }
            memset(b,0,sizeof(b));
            for(i=0;i<n;++i)
                if(a[i].a==0 && a[i].b==0)
                {
                    out[i]=p+97;
                    a[i].b=1;
                    for(j=0;j<n;++j)
                        if(a[j].a>0)
                            b[j].a+=abs(j-i);
                }
            for(j=0;j<n;++j)
                a[j].a-=b[j].a;
        }
        for(i=0;i<n;++i)
            printf("%c",out[i]);
        cout<<endl;
        
    }
    
    
    return 0;
}
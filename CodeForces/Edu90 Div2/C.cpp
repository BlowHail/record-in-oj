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
string s;
ll resv()
{
    ll res=0;
    int sum=0;
    int l=s.length();
    int cur=0;
    bool ok=true;
        // if(cur-l+sum*2<0)
        // {
        //     res+=i+1;
        //     int kk=a[i+1];
        //     res+=kk;
        //     int jjj=i+1,kkk=jjj+kk;
        //     while (a[kkk]-a[jjj])
        //     {
        //         res+=a[kkk]-a[jjj];
        //         int f=jjj;
        //         jjj=kkk;
        //         kkk=a[kkk]-a[f];
        //         /* code */
        //     }

        //     continue;
        // }
        for(int j=0;j<l;j++)
            {
                res++;
                if(s[j]=='+')
                    cur++;
                else
                {
                    cur--;
                }
                if(cur<0)
                    {
                        cur=0;
                        res+=j+1;
                    }
                
            }
            
    
    return res;
}
int main ()
{
    int T,i,t,j,k,p,sum=0;
    cin>>t;
    while (t--)
    {
        cin>>s;
        
        cout<<resv()<<endl;
        /* code */
    }
    
    
    return 0;
}
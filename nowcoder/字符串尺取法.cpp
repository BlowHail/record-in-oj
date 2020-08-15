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
string s;
int cnt[30];
bool cheak()
{
    for(int i=0;i<26;++i)
        if(cnt[i]==0)
            return false;
    return true;
}
int main ()
{
    int T,n,m,i,t,j,k,p;
    cin>>s;
    j=s.length();
    k=0;
    int mins=inf;
    for(i=0;i<j;++i)
    {
        cnt[s[i]-'a']++;
        while(cheak())
        {
            mins=min(mins,i-k);
            cnt[s[k++]-'a']--;
        }
    }
    cout<<mins+1<<endl;
    
    return 0;
}
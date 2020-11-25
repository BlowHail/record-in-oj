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
using namespace std;
string s, t;
int f[1000];
void get_f(string t)
{
    //对要查找的字符串进行匹配，寻找重复的地方
    int i=0,j=-1;
    f[0]=-1;
    int len=t.length();
    while(i<len)
    {
        if(j==-1 || t[i]==t[j])
        {
            i++;
            j++;
            f[i]=j;
        }
        else
            j=f[j];
    }
}
int kmp ()
{
    int lens=s.length();
    int lent=t.length();
    int i=0,j=0;
    //遍历，相同继续，不同则找之前记录的要查找字符的相同位置开始遍历
    while(i<lens)
    {
        if(j==-1 || s[i]==t[j])
        {
            i++;
            j++;
            if(j==lent)
                return 1;
        }
        else
            j=f[j];
    }
    return 0;
}
int main ()
{
    int n,m,i,j,k;
    cin>>s>>t;
    get_f(t);
    for(i=0;i<10;++i)
        cout<<f[i]<<" ";
    cout<<endl;
    cout<<kmp();

    return 0;
}
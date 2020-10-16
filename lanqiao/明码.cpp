#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int a[100000];

int main()
{
    for(int i=1;i<=320;++i)
        cin>>a[i];
    for(int i=1;i<=319;i+=2){
        cout<<bitset<8>(a[i])<<bitset<8>(a[i+1]);
        cout<<endl;
    }
    
    return 0;
}
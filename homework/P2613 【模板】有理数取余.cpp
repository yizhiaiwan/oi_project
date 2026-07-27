//
// Created by yizhiaiwan on 2026/7/20.
// from:
// https://www.luogu.com.cn/problem/P2613
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int const mod = 19260817;
string a,b;
int x,y;
int at,bt;
int exgcd(int a,int b,int &x,int &y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y = y - (a/b) * x;
    return d;
}



signed main() {
    cin>>a>>b;
    for (int i = 0;i<a.size();i++) {
        at = (at*10+a[i]-'0')%mod;
    }
    for (int i = 0;i<b.size();i++) {
        bt = (bt*10+b[i]-'0')%mod;
    }
    int inv = exgcd(bt,mod,x,y);
    if (at%inv) {
        cout<<"Angry!";
        return 0;
    }
    int ans=at*x%mod;
    cout<<(ans+mod)%mod;
}
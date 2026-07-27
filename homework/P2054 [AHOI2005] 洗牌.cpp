//
// Created by yizhiaiwan on 2026/7/20.
// from:
// https://www.luogu.com.cn/problem/P2054
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,l,p,x,y;
int exgcd(int a,int b,int &x,int &y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y = y-(a/b)*x;
    return d;
}
int q_pow(int a,int b) {
    int res = 1;
    while (b) {
        if (b&1) {
            res = (__int128)res*a%p;
        }
        a = (__int128)a*a%p;
        b>>=1;
    }
    return res;
}
signed main() {
    scanf("%lld%lld%lld",&n,&m,&l);
    p = n+1;
    int d = exgcd(q_pow(2,m),p,x,y);
    int t = p/d;
    int ans = ((__int128)x*(l/d)%t+t)%t;
    cout<<ans;
}
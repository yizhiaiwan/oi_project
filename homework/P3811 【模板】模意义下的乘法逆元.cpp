//
// Created by yizhiaiwan on 2026/7/20.
// from:
// https://www.luogu.com.cn/problem/P3811
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6+10;
int inv[N];
int n,m;



signed main() {
    cin>>n>>m;
    inv[1] = 1;;
    for (int i = 2;i<=n;i++) {
        inv[i] = (m-m/i)*inv[m%i]%m;
    }
    for (int i = 1;i<=n;i++) {
        printf("%lld\n",inv[i]);
    }
    return 0;
}
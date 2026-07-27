//
// Created by yizhiaiwan on 2026/7/21.
// from:
// https://www.luogu.com.cn/problem/P1595
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int c[30][30];
int fac[30];
void init() {
    for (int i = 0;i<=n;i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1;j<i;j++) {
            c[i][j] = c[i-1][j]+c[i-1][j-1];
        }
    }
    fac[0] = fac[1] = 1;
    for (int i = 2;i<=n;i++) fac[i] = fac[i-1]*i;
}

signed main() {
    cin>>n;
    init();
    for (int i = 0;i<=n;i++) {
        if (i&1) ans-=c[n][i]*fac[n-i];
        else ans+=c[n][i]*fac[n-i];
    }
    cout<<ans;
}
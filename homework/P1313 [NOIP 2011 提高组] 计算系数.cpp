//
// Created by yizhiaiwan on 2026/7/20.
// from:
// https://www.luogu.com.cn/problem/P1313
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10,mod = 10007;
int c[N][N];
int a,b,k,n,m;

int q_pow(int a,int b) {
    int res = 1;
    while (b) {
        if (b&1) {
            res *= a;
            res %= mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}

void init() {
    c[0][0] = 1;
    for (int i = 1;i<=k;i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1;j<i;j++) {
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}


signed main() {
    scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
    init();
    printf("%lld",(c[k][n]%mod*q_pow(a,n)%mod*q_pow(b,m)%mod)%mod);
}
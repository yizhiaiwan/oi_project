//
// Created by yizhiaiwan on 2026/7/21.
// from:
// https://www.luogu.com.cn/problem/P3807
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int n,m,p,t;
int fac[N], inv[N];
void init(int p) {
    fac[0] = 1;
    for (int i = 1;i<p;i++) fac[i] = fac[i-1]*i%p;
    inv[0] = inv[1] = 1;
    for (int i = 2;i<p;i++) {
        inv[i] = (p-p/i)*inv[p%i]%p;// 线性递推求逆元
    }
    for (int i = 2;i<p;i++) {
        inv[i] = inv[i-1]*inv[i]%p;
    }
}
int C(int n,int m,int p) {
    if (m > n) return 0;
    return fac[n] * inv[m] % p * inv[n-m] % p;
}
int lucas(int n,int m,int p) {
    if (m == 0) return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}
signed main() {
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld%lld%lld",&n,&m,&p);
        init(p);
        cout<<lucas(n+m,m,p)<<"\n";
    }
}
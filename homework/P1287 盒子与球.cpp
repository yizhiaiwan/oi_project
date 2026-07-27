//
// Created by yizhiaiwan on 2026/7/21.
// from:
// https://www.luogu.com.cn/problem/P1287
//
#include <bits/stdc++.h>
using namespace std;
int c[20][20];
int n,r;
void init() {
    for (int i = 0;i<=n;i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1;j<i;j++) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
}
// 快速幂
int q_pow(int a,int b) {
    int res = 1;
    while (b) {
        if (b&1) {
            res *= a;
        }
        a*=a;
        b>>=1;
    }
    return res;
}

int main() {
    cin>>n>>r;
    init();
    int ans = q_pow(r,n);
    for (int i = 1;i<=n;i++) {
        if (i&1) ans-=c[r][i]*q_pow(r-i,n);
        else ans+=c[r][i]*q_pow(r-i,n);
    }
    cout<<ans;
}
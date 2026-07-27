//
// Created by yizhiaiwan on 2026/7/2.
// from:
// https://www.luogu.com.cn/problem/P1040
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
long long f[N][N];
int n;
int a[N];




int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for (int len = 2;len<=n;len++) {
        for (int i = 1;i+len-1<=n;i++) {
            int j = i+len-1;
            for (int k = i;k<j;k++) {
                f[i][j] = max(f[i][j],f[i][k-1]*f[k+1][j]+a[k]);
            }
        }
    }
    printf("%lld",f[1][n]);
}
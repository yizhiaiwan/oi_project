//
// Created by yizhiaiwan on 2026/7/1.
// from:
// https://www.luogu.com.cn/problem/P17015
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
long long f[N][N];
int a[N];
int n;




int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    for (int len = 1;len<=n;len++) {
        for (int i = 1;i+len-1<=n;i++) {
            int j = i+len-1;
            for (int k = i;k<=j;k++) {
                f[i][j] = max(f[i][j],f[i][k-1]+f[k+1][j]+a[i-1]+a[j+1]);
            }
        }
    }
    cout<<f[1][n];
}
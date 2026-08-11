//
// Created by yizhiaiwan on 2026/7/30.
// from:
// https://www.luogu.com.cn/problem/B3647
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int f[N][N][N];
int n,m;

void Floyd() {
    for (int i = 1;i<=n;i++) {
        f[0][i][i] = 0;
    }
    for (int k = 1;k<=n;k++) {
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=n;j++) {
                f[k][i][j] = min(f[k-1][i][j],f[k-1][i][k]+f[k-1][k][j]);
            }
        }
    }
}



int main() {
    memset(f,0x3f,sizeof f);
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        f[0][u][v] = min(w,f[0][u][v]);
        f[0][v][u] = min(w,f[0][v][u]);
    }
    Floyd();
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            printf("%d ",f[n][i][j]);
        }
        printf("\n");
    }
}
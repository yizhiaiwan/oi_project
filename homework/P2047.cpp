//
// Created by yizhiaiwan on 2026/8/3.
// from:
// https://www.luogu.com.cn/problem/P2047
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2+10,INF = 0x3f3f3f3f;
int n,m;
int c[N][N],dis[N][N];
double I[N];

void init() {
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            dis[i][j] = 0;
            if (i!=j) {
                dis[i][j] = INF;
            }
        }
    }
}


signed main() {
    scanf("%d%d",&n,&m);
    init();
    for (int i = 1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        dis[u][v] = dis[v][u] = min(dis[u][v],w);
        c[u][v] = c[v][u] = 1;
    }
    for (int k = 1;k<=n;k++) {
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=n;j++) {
                if (dis[i][j]>dis[i][k]+dis[k][j]) {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    c[i][j] = c[i][k]*c[k][j];
                }
                else if (dis[i][j] == dis[i][k]+dis[k][j]) {
                    c[i][j] += c[i][k]*c[k][j];
                }
            }
        }
    }
    for (int v = 1;v<=n;v++) {
        for (int i = 1;i<=n;i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || j == v || v == i) continue;
                if (dis[i][j] == dis[i][v]+dis[v][j]) {
                    I[v] += (double)(c[i][v]*c[v][j])/c[i][j];
                }
            }
        }
    }
    for (int i = 1;i<=n;i++) {
        printf("%.3lf\n",I[i]);
    }
}
//
// Created by yizhiaiwan on 2026/8/3.
// from:
// https://www.luogu.com.cn/problem/P10927
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2+10,M = 1e4+10,INF = 0x3f3f3f3f;
int n,m,ans = INF;
int g[N][N],dis[N][N],p[N][N];
vector<int> path;


void get_path(int i,int j) {
    if (p[i][j] == 0) {
        return;
    }
    int k = p[i][j];
    get_path(i,k);
    path.push_back(k);
    get_path(k,j);
}


signed main() {
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            if (i!=j) g[i][j] = INF;
        }
    }
    for (int i = 1;i<=m;i++) {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        g[u][v] = w;
        g[v][u] = w;
    }
    memcpy(dis,g,sizeof dis);
    for (int k = 1;k<=n;k++) {
        for (int i = 1;i<k;i++) {
            for (int j = 1+i;j<k;j++) {
                if (ans > dis[i][j]+g[i][k]+g[k][j]) {
                    ans = dis[i][j]+g[i][k]+g[k][j];
                    path.clear();
                    path.push_back(i);
                    get_path(i,j);
                    path.push_back(j);
                    path.push_back(k);
                }
            }
        }
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=n;j++) {
                if (dis[i][j]>dis[i][k]+dis[k][j]) {
                    dis[i][j] = dis[i][k]+dis[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
    if (ans == INF) {
        printf("No solution.");
        return 0;
    }
    for (int &i:path) {
        printf("%lld ",i);
    }
}
//
// Created by yizhiaiwan on 2026/7/30.
// from:
// https://www.luogu.com.cn/problem/P6464
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int f[N][N],g[N][N];
int n,m,ans = 1e9;

void Floyd() {
    for (int i = 1;i<=n;i++) {
        f[i][i] = 0;
    }
    for (int k = 1;k<=n;k++) {
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=n;j++) {
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}

int find() {
    int res = 0;
    for (int i = 1;i<=n;i++) {
        for (int j = i+1;j<=n;j++) {
            res += f[i][j];
        }
    }
    return res;
}

void mini_floyd(int a,int b) {
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            f[i][j] = min(f[i][j],f[i][a]+f[a][j]);
        }
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            f[i][j] = min(f[i][j],f[i][b]+f[b][j]);
        }
    }
}


int main() {
    memset(g,0x3f,sizeof g);
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u][v] = w;
        g[v][u] = w;
    }
    memcpy(f,g,sizeof f);
    Floyd();
    memcpy(g,f,sizeof g);
    for (int u = 1;u<=n;u++) {
        for (int v = u+1;v<=n;v++) {
            memcpy(f,g,sizeof f);
            f[u][v] = 0;
            f[v][u] = 0;
            mini_floyd(u,v);
            int sum = 0;
            for (int i = 1;i<=n;i++) {
                for (int j = i+1;j<=n;j++) {
                    sum+=f[i][j];
                }
            }
            ans = min(sum,ans);
        }
    }
    printf("%d",ans);
}
//
// Created by yizhiaiwan on 2026/5/24.
// from:
// https://www.luogu.com.cn/problem/P3366
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int g[N][N],dis[N],vis[N];
int mst,n,m;

void prim() {
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[1] = 0;
    for (int i = 1;i<=n;i++) {
        int min_point = 0;
        for (int j = 1;j<=n;j++) {
            if (!vis[j] && dis[j]<dis[min_point]) min_point = j;
        }
        if (dis[min_point] == 0x3f3f3f3f) {
            printf("orz");
            exit(0);
        }
        vis[min_point] = 1;
        mst += dis[min_point];
        for (int y = 1;y<=n;y++) {
            if (!vis[y]) dis[y] = min(dis[y],g[min_point][y]);
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);
    for (int i = 1;i<=m;i++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (z<g[x][y]) {
            g[x][y] = z;
            g[y][x] = z;
        }
    }
    prim();
    printf("%d",mst);
    return 0;
}
//
// Created by yizhiaiwan on 2026/5/27.
// from:
// https://www.luogu.com.cn/problem/P1546
//
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int g[N][N],dis[N],vis[N];
int n,ans;

void prim() {
    memset(dis,0x3f,sizeof dis);
    dis[1] = 0;
    for (int i = 1;i<=n;i++) {
        int x = 0;
        for (int j = 1;j<=n;j++) {
            if (!vis[j] && dis[j]<dis[x]) {
                x = j;
            }
        }
        if (x==0x3f3f3f3f) {
            return;
        }
        vis[x] = 1;
        ans+=dis[x];
        for (int j = 1;j<=n;j++) {
            if (!vis[j])dis[j] = min(dis[j],g[x][j]);
        }
    }
}



int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            scanf("%d",&g[i][j]);
        }
    }
    prim();
    printf("%d",ans);
}
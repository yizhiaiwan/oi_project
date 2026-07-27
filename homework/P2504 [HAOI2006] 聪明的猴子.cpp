//
// Created by yizhiaiwan on 2026/5/24.
// from:
// https://www.luogu.com.cn/problem/P2504
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int dis[N],vis[N],a[N];
pair<int,int> g[N];
int n,m,mst;

int finddis(int x,int y) {
    int i = g[x].first-g[y].first;
    int j = g[x].second-g[y].second;
    return j*j+i*i;
}

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
            return;
        }
        vis[min_point] = 1;
        mst = max(mst,dis[min_point]);
        for (int y = 1;y<=n;y++) {
            int d = finddis(min_point,y);
            if (!vis[y]) dis[y] = min(dis[y],d);
        }
    }
}

int main() {
    scanf("%d",&m);
    for (int i = 1;i<=m;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%d%d",&g[i].first,&g[i].second);
    }
    prim();
    int tnt = 0;
    for (int i = 1;i<=m;i++) {
        if (a[i]*a[i]>=mst) {
            tnt++;
        }
    }
    printf("%d",tnt);
    return 0;
}
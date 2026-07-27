//
// Created by yizhiaiwan on 2026/5/31.
// from:
// https://www.luogu.com.cn/problem/P4180
//
#include <bits/stdc++.h>
using namespace std;
// cs题目😡😡😡
// 先求出最小生成树，然后找出一个点严格大于最小生成树的最大点的点(这个点不属于最小生成树中)
// 然后使用mst减掉替代的点之后再加上替代点的值
#define int long long
const int N = 3e5 + 10;
int n, m, mst, ans = INT64_MAX;
int f[N], lg[N], st[N][21], dep[N], vis[N];

struct edge {
    int x, y, w;
} e[N];

struct point {
    int max_i, s_max_i;
} g[N][21];
struct node {
    int x,w;
};
vector<node> ne[N];
void dfs(int x, int pre, int w) {
    st[x][0] = pre;
    dep[x] = dep[pre] + 1;
    g[x][0].max_i = w;
    g[x][0].s_max_i = INT32_MIN;
    for (int i = 1; i <= lg[dep[x]] + 1; i++) {
        int j = st[x][i - 1];
        st[x][i] = st[j][i - 1];
        g[x][i].max_i = max(g[x][i - 1].max_i, g[j][i - 1].max_i);
        if (g[x][i - 1].max_i > g[j][i - 1].max_i) {
            g[x][i].s_max_i = max(g[j][i - 1].max_i, g[x][i - 1].s_max_i);// 上比下大，最大在上次与下大
        } else if (g[x][i - 1].max_i < g[j][i-1].max_i) {
            g[x][i].s_max_i = max(g[x][i-1].max_i,g[j][i-1].s_max_i);// 上比下小，最大在上大与下次
        }else {
            g[x][i].s_max_i = max(g[x][i-1].s_max_i,g[j][i-1].s_max_i);// 上等于下，最大在上次与下次
        }
    }
    for (node i:ne[x]) {
        if (i.x!=pre) dfs(i.x,x,i.w);
    }
}

int LCA(int x,int y) {
    if (dep[x]<dep[y]) swap(x,y);
    for (int i = 20;i>=0;i--) {
        if (dep[st[x][i]]>=dep[y]) {
            x = st[x][i];
        }
    }
    if (x==y) return x;
    for (int i = 20;i>=0;i--) {
        if (st[x][i] != st[y][i]) {
            x = st[x][i],y = st[y][i];
        }
    }
    return st[x][0];
}
void init() {
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    dfs(1, 0, 0);
}
int find(int x) {
    if (f[x] != x) {
        return f[x] = find(f[x]);
    }
    return f[x];
}
void kruskal() {
    sort(e + 1, e + m + 1, [](edge a, edge b) { return a.w < b.w; });
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x = e[i].x, y = e[i].y, w = e[i].w;
        int rx = find(x), ry = find(y);
        if (rx != ry) {
            f[rx] = ry;
            mst += w;
            vis[i] = 1;
            ne[x].push_back({y,w});
            ne[y].push_back({x,w});
        }
    }
}
int get(int x,int y,int w) {
    int maxx = INT32_MIN;
    for (int j = lg[dep[x]-dep[y]]+1;j>=0;j--) {
        if (dep[st[x][j]]>=dep[y]) {
            if (g[x][j].max_i==w) maxx = max(maxx,g[x][j].s_max_i);
            else maxx = max(maxx,g[x][j].max_i);
            x = st[x][j];
        }
    }
    return maxx;
}
signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &e[i].x, &e[i].y, &e[i].w);
    }
    // 1. 求出最小生成树的大小
    kruskal();
    // 2. 初始化st表
    init();
    for (int i = 1;i<=m;i++) {
        if (vis[i]) continue;
        int x = e[i].x,y = e[i].y,w = e[i].w;
        int lca = LCA(x,y);
        int w_ = max(get(x,lca,w),get(y,lca,w));
        ans = min(ans,mst-w_+w);
    }
    printf("%lld",ans);
    return 0;
}

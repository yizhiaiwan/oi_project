//
// Created by yizhiaiwan on 2026/8/1.
// from:
// https://www.luogu.com.cn/problem/P15803
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e3+10,INF = 0x7f7f7f7f7f7f7f7f; // INF的值一定要修改为 long long 的最大值，否则会导致答案判断失效
int n,m;
struct edge {
    int v,w,b;
};
struct edge1 {
    int u,v,w,b;
}a[M];
vector<vector<edge>> g(M);
int dis[M],vis[M];
typedef pair<int,int> PII;
int dijk(int s,int ban) {
    memset(dis, 0x7f, sizeof dis);
    memset(vis,0,sizeof vis);
    dis[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> que;
    que.push({0, s});
    while (!que.empty()) {
        int top = que.top().second;
        que.pop();
        if (vis[top]) continue;
        vis[top] = 1;
        for (auto &edge : g[top]) {          // 遍历 vector 邻接表
            if (edge.b > ban) continue;  // 如果边的编号等于 ban，则跳过
            int v = edge.v, w = edge.w;
            if (dis[v] > dis[top] + w) {
                dis[v] = dis[top] + w;
                que.push({dis[v], v});
            }
        }
    }
    return dis[n];
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w, b;
        scanf("%lld%lld%lld%lld", &u, &v, &w, &b);
        g[u].push_back({v, w, b});
        g[v].push_back({u, w, b});
        a[i] = {u, v, w, b};
    }
    int ans = INF;
    for (int i = 1;i<=m;i++) {
        int u = a[i].u,v = a[i].v,w = a[i].w,b = a[i].b;
        for (auto &edge : g[u]) {
            if (edge.v == v && edge.b == b) {
                edge.w = 0;
                break;
            }
        }
        for (auto &edge : g[v]) {
            if (edge.v == u && edge.b == b) {
                edge.w = 0;
                break;
            }
        }
        int res = dijk(1,b);
        for (auto &edge : g[u]) {
            if (edge.v == v && edge.b == b) {
                edge.w = w;
                break;
            }
        }
        for (auto &edge : g[v]) {
            if (edge.v == u && edge.b == b) {
                edge.w = w;
                break;
            }
        }
        ans = min(ans, res);
    }
    if (ans == INF) {
        printf("-1");
    } else {
        printf("%lld", ans);
    }
}
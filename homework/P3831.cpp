//
// Created by yizhiaiwan on 2026/7/29.
// from:
// https://www.luogu.com.cn/problem/P3831
//
#include <bits/stdc++.h>
using namespace std;
const int N = 8e5+10;
typedef pair<int,int> PII;
struct point {
    int x,y,id;
}a[N];
int dis[N],vis[N];
vector<vector<PII>> g(N);
int n,m,mx;
int s,e;
int dijkstra() {
    priority_queue<PII,vector<PII>,greater<PII>> que;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s] = dis[s+mx] = 0;
    que.push({0,s});
    que.push({0,s+mx});
    while (!que.empty()) {
        auto t = que.top();
        que.pop();
        if (vis[t.second]) continue;
        vis[t.second] = 1;
        for (auto &edge : g[t.second]) {
            int u = edge.first, w = edge.second;
            if (dis[u] > dis[t.second] + w) {
                dis[u] = dis[t.second] + w;
                que.push({dis[u], u});
            }
        }
    }
    return min(dis[e],dis[e+mx]);
}


int main() {
    scanf("%d%d",&n,&m);
    mx = m+2;
    for (int i = 1;i<=mx;i++) {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].id = i;
    }
    s = m+1;
    e = m+2;
    sort(a+1,a+mx+1,[](point a,point b) {
        if (a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
    });
    for (int i = 2;i<=mx;i++) {
        if (a[i].x == a[i-1].x) {
            int u = a[i].id+mx,v = a[i-1].id+mx,w = 2*abs(a[i].y-a[i-1].y);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    }
    sort(a+1,a+mx+1,[](point a,point b) {
        if (a.y!=b.y) return a.y<b.y;
        return a.x<b.x;
    });
    for (int i = 2;i<=mx;i++) {
        if (a[i].y == a[i-1].y) {
            int u = a[i].id,v = a[i-1].id,w = 2*abs(a[i].x-a[i-1].x);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
    }

    for (int i = 1;i<=m;i++) {
        int u = i,v = i+mx;
        g[u].push_back({v,1});
        g[v].push_back({u,1});
    }

    g[s].push_back({s+mx,0});
    g[s+mx].push_back({s,0});
    g[e].push_back({e+mx,0});
    g[e+mx].push_back({e,0});
    printf("%d",dijkstra());
}
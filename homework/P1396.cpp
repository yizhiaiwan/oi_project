//
// Created by yizhiaiwan on 2026/8/7.
// from:
// https://www.luogu.com.cn/problem/P1396
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int n,m,s,t;
int dis[N];
struct edge {
    int v,w,ne;
}e[N<<2];
int h[N],idx;
void add(int u,int v,int w) {
    e[++idx] = {v,w,h[u]};
    h[u] = idx;
}
int dijkstra(int s) {
    priority_queue<pair<int,int>> q;
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    q.push({0,s});
    while(!q.empty()) {
        auto [d,u] = q.top();
        q.pop();
        if(d > dis[u]) continue;
        for(int i=h[u];i;i=e[i].ne) {
            int v = e[i].v,w = e[i].w;
            int nd = max(dis[u],w);
            if(nd < dis[v]) {
                dis[v] = nd;
                q.push({-dis[v],v});
            }
        }
    }
    return dis[t];
}

int main() {
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=0;i<m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    printf("%d",dijkstra(s));
}
//
// Created by yizhiaiwan on 2026/5/17.
// from:
// https://www.luogu.com.cn/problem/P3379
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,s,x,y,a,b;
vector<int> e[N];
vector<pair<int,int>> query[N];
int fa[N],ans[N];
bool vis[N];

int find(int x) {
    return fa[x]==x? x:fa[x] = find(fa[x]);
}

void dfs(int u) {
    vis[u] = 1;
    for (int v:e[u]) {
        if (!vis[v]) {
            dfs(v);
            fa[v] = u;
        }
    }
    for (auto& it:query[u]) {
        int v = it.first,i = it.second;
        if (vis[v]) ans[i]=find(v);
    }
}

int main() {
    scanf("%d%d%d",&n,&m,&s);
    for (int i = 1;i<n;i++) {
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1;i<=m;i++) {
        scanf("%d%d",&a,&b);
        query[a].push_back({b,i});
        query[b].push_back({a,i});
    }
    for (int i = 1;i<=n;i++) fa[i] = i;
    dfs(s);
    for (int i = 1;i<=m;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
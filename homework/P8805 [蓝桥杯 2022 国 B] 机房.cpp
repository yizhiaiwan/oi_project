//
// Created by yizhiaiwan on 2026/5/24.
// from:
// https://www.luogu.com.cn/problem/P8805
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int f[N][21],dep[N],st[N];
int n,m;
vector<int> g[N];

void dfs(int x,int pre) {
    dep[x] = dep[pre]+1;
    st[x] = st[pre]+g[x].size();
    f[x][0] = pre;
    for (int i = 1;i<=20;i++) {
        f[x][i] = f[f[x][i-1]][i-1];
    }
    for (auto& i:g[x]) {
        if (i!=pre) dfs(i,x);
    }
}
int LCA(int a,int b) {
    if (dep[a]<dep[b]) swap(a,b);
    for (int i = 20;i>=0;i--) {
        if (dep[f[a][i]]>=dep[b]) {
            a = f[a][i];
        }
    }
    if (a==b) return b;

    for (int i = 20;i>=0;i--) {
        if (f[a][i]!=f[b][i]) {
            a = f[a][i],b = f[b][i];
        }
    }
    return f[a][0];
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for (int i = 1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x==y) {
            printf("%d\n",g[x].size());
        }
        else {
            int lca = LCA(x,y);
            printf("%d\n",st[x]-2*st[lca]+st[y]+(int)g[lca].size());
        }
    }
}
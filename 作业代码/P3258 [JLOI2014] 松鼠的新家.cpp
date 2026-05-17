//
// Created by yizhiaiwan on 2026/5/17.
// from:
// https://www.luogu.com.cn/problem/P3258
//
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int f[N][21],dep[N],d[N],v[N];
vector<int> g[N];
int n;
void dfs_sum(int x,int pre) {
    for (auto& i:g[x]) {
        if (i!=pre) {
            dfs_sum(i,x);
            d[x]+=d[i];
        }
    }
}
void dfs(int x,int pre) {
    dep[x] = dep[pre]+1;
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
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%d",&v[i]);
    }
    for (int i = 1;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for (int i = 1;i<n;i++) {
        int x = v[i],y = v[i+1];
        int lca = LCA(x,y);
        d[x]++,d[y]++,d[lca]--,d[f[lca][0]]--;
    }
    dfs_sum(1,0);
    for (int i = 2;i<=n;i++) {
        d[v[i]]--;
    }
    for (int i = 1;i<=n;i++) {
        printf("%d\n",d[i]);
    }
    return 0;
}
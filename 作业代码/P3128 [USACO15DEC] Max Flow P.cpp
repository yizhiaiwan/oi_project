//
// Created by yizhiaiwan on 2026/5/17.
// from:
// https://www.luogu.com.cn/problem/P3128
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
vector<int> g[N];
int n,m,s,ans = -0x3fffffff;
int f[N][21],dep[N],d[N];
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
void dfs2(int x,int pre) {
    for (auto& i:g[x]) {
        if (i!=pre) {
            dfs2(i,x);
            d[x]+=d[i];
        }
    }
    ans = max(d[x],ans);
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
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for (int i = 1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        int lca = LCA(x,y);
        d[x]++,d[y]++,d[lca]--,d[f[lca][0]]--;
    }
    dfs2(1,0);
    cout<<ans;
    return 0;
}
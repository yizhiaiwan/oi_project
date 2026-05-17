//
// Created by yizhiaiwan on 2026/5/17.
// from:
// https://www.luogu.com.cn/problem/P6869
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int f[N][21],deps[N],c_one[N],c_two[N],d[N];
struct edge {
    int e,c1,c2;
};
vector<edge> g[N];
int n,ans;
void dfs(int x,int pre) {
    f[x][0] = pre;
    deps[x] = deps[pre]+1;
    for (int i = 1;i<=20;i++) {
        f[x][i] = f[f[x][i-1]][i-1];
    }
    for (auto& i:g[x]) {
        if (i.e!=pre) {
            c_one[i.e] = i.c1;
            c_two[i.e] = i.c2;
            dfs(i.e,x);

        }
    }
}
void dfs_sum(int x,int pre) {
    for (auto& i:g[x]) {
        if (i.e!=pre) {
            dfs_sum(i.e,x);
            d[x]+=d[i.e];
        }
    }
}
int LCA(int x,int y) {
    if (deps[x]<deps[y]) {
        swap(x,y);
    }
    for (int i = 20;i>=0;i--) {
        if (deps[f[x][i]]>=deps[y]) {
            x = f[x][i];
        }
    }
    if (x==y) return y;
    for (int i = 20;i>=0;i--) {
        if (f[x][i]!=f[y][i]) {
            x = f[x][i],y = f[y][i];
        }
    }
    return f[x][0];
}

signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<n;i++) {
        int a,b,c1,c2;
        scanf("%lld%lld%lld%lld",&a,&b,&c1,&c2);
        g[a].push_back({b,c1,c2});
        g[b].push_back({a,c1,c2});
    }
    dfs(1,0);
    for (int i = 1;i<n;i++) {
        int j = i+1;
        int lca = LCA(i,j);
        d[i]++,d[j]++,d[lca]-=2;
    }
    dfs_sum(1,0);
    for (int i = 1;i<=n;i++) {
        ans+=min(d[i]*c_one[i],c_two[i]);
    }
    printf("%lld",ans);
}
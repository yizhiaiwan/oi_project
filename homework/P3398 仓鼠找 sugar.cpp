//
// Created by yizhiaiwan on 2026/5/17.
// from:
// https://www.luogu.com.cn/problem/P3398
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int f[N][21],deps[N];
int n,q;
vector<int> g[N];

void dfs(int x,int pre) {
    deps[x] = deps[pre]+1;
    f[x][0] = pre;
    for (int i = 1;i<=20;i++) {
        f[x][i] = f[f[x][i-1]][i-1];
    }
    for (auto& i:g[x]) {
        if (i!=pre) {
            dfs(i,x);
        }
    }
}
int lca(int x,int y) {
    if (deps[x]<deps[y])swap(x,y);
    for (int i = 20;i>=0;i--) {
        if (deps[f[x][i]]>=deps[y]) {
            x = f[x][i];
        }
    }
    if (x==y) return x;
    for (int i = 20;i>=0;i--) {
        if (f[x][i]!=f[y][i]) {
            x = f[x][i],y = f[y][i];
        }
    }
    return f[x][0];
}
int main() {
    scanf("%d%d",&n,&q);
    for (int i = 1;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for (int i = 1;i<=q;i++) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int x = lca(a,b),y = lca(c,d);
        if (deps[x]<deps[y]) {
            swap(x,y);
            swap(a,c);
            swap(b,d);
        }
        if (lca(c,x)==x || lca(x,d)==x) {
            printf("Y\n");
        }else {
            printf("N\n");
        }
    }
    return 0;
}
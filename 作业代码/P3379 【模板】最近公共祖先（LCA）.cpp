//
// Created by yizhiaiwan on 2026/5/10.
// form:
// https://www.luogu.com.cn/problem/P3379
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
vector<int> g[N];
int n,m,s;
int f[N][21],dep[N];
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
    scanf("%d%d%d",&n,&m,&s);
    for (int i = 1;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(s,0);
    for (int i = 1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",LCA(x,y));
    }
}
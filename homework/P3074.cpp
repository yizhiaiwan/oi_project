//
// Created by yizhiaiwan on 2026/8/7.
// from:
// https://www.luogu.com.cn/problem/P3074
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
int n,m;
int t[N],in[N],f[N];
vector<vector<int>>g(N);
int ans;
void Topological_sort() {
    queue<int> que;
    for (int i = 1;i<=n;i++) {
        if (in[i] == 0) {
            que.push(i);
            f[i] = t[i];
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ans = max(ans,f[u]);
        for (int v:g[u]) {
            f[v] = max(f[v], f[u] + t[v]);
            if (--in[v]==0) {
                que.push(v);
            }
        }
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++) {
        scanf("%d",&t[i]);
    }
    for (int i = 1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        in[v]++;
    }
    Topological_sort();
    printf("%d",ans);
}
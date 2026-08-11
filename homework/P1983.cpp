//
// Created by yizhiaiwan on 2026/8/7.
// from:
// https://www.luogu.com.cn/problem/P1983
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m;
int ans = -1;
int in[N],vis[N][N];
vector<vector<int>> g(N);
struct node {
    int u,step;
};

void Topological_sort() {
    queue<node> que;
    for (int i = 1;i<=n;i++) {
        if (in[i] == 0) {
            que.push({i,1});
        }
    }
    while (!que.empty()) {
        const auto [u,step] = que.front();
        ans = max(ans,step);
        que.pop();
        for (const int &v:g[u]) {
            if (--in[v] == 0) {
                que.push({v,step+1});
            }
        }
    }
}


int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=m;i++) {
        int t;
        scanf("%d",&t);
        vector<int> stop,run;
        for (int j = 1;j<=t;j++) {
            int x;
            scanf("%d",&x);
            stop.push_back(x);
        }
        for (int j = stop[0];j<=stop.back();j++) {
            if (!binary_search(stop.begin(), stop.end(), j)) {
                run.push_back(j);
            }
        }
        for (auto &u:stop) {
            for (auto &v:run) {
                if (!vis[u][v] && !binary_search(stop.begin(), stop.end(), v)) {
                    vis[u][v] = 1;
                    g[u].push_back(v);
                    in[v]++;
                }
            }
        }
    }
    Topological_sort();
    printf("%d",ans);
}
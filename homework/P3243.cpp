//
// Created by yizhiaiwan on 2026/8/7.
// form:
// https://www.luogu.com.cn/problem/P3243
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t,n,m;

vector<vector<int>> g(N);
int in[N];
vector<int> ans;

void Topological_sort() {
    priority_queue<int> que;
    for (int i = 1;i<=n;i++) {
        if (in[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int u = que.top();
        ans.push_back(u);
        que.pop();
        for (auto v:g[u]) {
            if (--in[v] == 0) {
                que.push(v);
            }
        }
    }
}

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&n,&m);
        for (int i = 1;i<=n;i++) {
            g[i].clear();
        }
        ans.clear();
        memset(in,0,sizeof in);
        for (int i = 1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            g[v].push_back(u);
            in[u]++;
        }
        Topological_sort();
        reverse(ans.begin(),ans.end());
        if (ans.size() != n) {
            printf("Impossible! \n");
            continue;
        }
        for (int i = 0;i<ans.size();i++) {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}
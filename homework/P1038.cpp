//
// Created by yizhiaiwan on 2026/8/7.
// from:
// https://www.luogu.com.cn/problem/P1038
//
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n,p,cnt;
int C[N],U[N],ans[N];
int in[N],out[N];
struct node {
    int v,w;
};
vector<vector<node>> g(N);

void Topological_sort() {
    queue<int> que;
    for (int i = 1;i<=n;i++) {
        if (C[i]>0) {
            que.push(i);
        }else {
            C[i]-=U[i];
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto i:g[u]) {
            auto [v,w] = i;
            if (C[u]>0) {
                C[v] += C[u]*w;
            }
            in[v]--;
            if (in[v]==0) que.push(v);
        }
    }
}


int main() {
    scanf("%d%d",&n,&p);
    for (int i = 1;i<=n;i++) {
        scanf("%d%d",&C[i],&U[i]);
    }
    for (int i = 1;i<=p;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        in[v]++;
        out[u]++;
    }
    Topological_sort();
    bool flag = false;
    for (int i = 1;i<=n;i++) {
        if (out[i] == 0 && C[i]>0) {
            ans[++cnt] = i;
            printf("%d %d\n",i,C[i]);
            flag = 1;
        }
    }
    if (flag==false) printf("NULL");
}
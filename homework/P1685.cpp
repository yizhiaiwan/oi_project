//
// Created by yizhiaiwan on 2026/8/7.
// from:
// https://www.luogu.com.cn/problem/P1685
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10,mod = 10000;
int n,m,start,en,en_time;
int ans;
struct node{int v,w;};
vector<vector<node>> g(N);
int in[N],cnt[N],sum[N];

void Topological_sort() {
    queue<int> que;
    for (int i = 1;i<=n;i++) {
        if (in[i]==0 && i!=start) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto i:g[u]) {
            auto [v,w] = i;
            if (--in[v]==0) {
                que.push(v);
            }
        }
    }
    que.push(start);
    cnt[start] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto i:g[u]) {
            auto [v,w] = i;
            cnt[v] = (cnt[u]+cnt[v])%mod;
            sum[v] = (sum[u]+sum[v] + cnt[u]*w)%mod;
            if (--in[v] == 0) {
                que.push(v);
            }
        }
    }
}



int main() {
    scanf("%d%d%d%d%d",&n,&m,&start,&en,&en_time);
    for (int i = 1;i<=m;i++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].push_back({v,w});
        in[v]++;
    }
    Topological_sort();
    ans = (sum[en]+(cnt[en]-1)*en_time)%mod;
    printf("%d",ans);
}
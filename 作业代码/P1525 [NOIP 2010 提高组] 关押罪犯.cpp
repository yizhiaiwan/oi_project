//
// Created by yizhiaiwan on 2026/4/20.
// from:
// https://www.luogu.com.cn/problem/P1525
//
#include <bits/stdc++.h>
using namespace std;
const int N = 20000 + 10;
int f[N << 1];
int n, m;

struct edge {
    int x, y, w;
};

vector<edge> edges;

int find(const int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void merge(const int x, const int y) {
    int r1 = find(x), r2 = find(y);
    if (r1 != r2) {
        f[r1] = r2;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 2; i++) f[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        edges.push_back({x, y, w});
    }
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) { return a.w > b.w; });
    for (const auto &e: edges) {
        int x = e.x, y = e.y, w = e.w;
        if (find(x) == find(y)) {
            printf("%d\n", w);
            return 0;
        }
        merge(x, y + n);
        merge(x + n, y);
    }
    printf("%d\n", 0);
}

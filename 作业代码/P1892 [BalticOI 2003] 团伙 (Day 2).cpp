//
// Created by yizhiaiwan on 2026/4/19.
// from :
// https://www.luogu.com.cn/problem/P1892
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int f[N * 2];
int n, m;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void merge(int x, int y) {
    int r1 = find(x);
    int r2 = find(y);
    if (r1 != r2) {
        f[r2] = r1;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        char opt;
        cin >> opt >> x >> y;
        if (opt == 'E') {
            merge(x, y + n);
            merge(y, x + n);
        } else {
            merge(x, y);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            ans++;
        }
    }
    printf("%d\n", ans);
}

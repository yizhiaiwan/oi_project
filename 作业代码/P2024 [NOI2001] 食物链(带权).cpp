//
// Created by yizhiaiwan on 2026/4/26.
// from:
// https://www.luogu.com.cn/problem/P2024
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int f[N], dis[N];
int n, k, ans;

int find(int x) {
    if (f[x] != x) {
        int root = find(f[x]);
        dis[x] += dis[f[x]];
        f[x] = root;
    }
    return f[x];
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= k; i++) {
        int opt, x, y;
        scanf("%d%d%d", &opt, &x, &y);
        int r1 = find(x), r2 = find(y);
        if (x > n || y > n || (opt == 2 && x == y)) {
            ans++;
            continue;
        }
        if (opt == 1) {
            if (r1 == r2 && ((dis[x] - dis[y]) % 3 + 3) % 3 != 0) {
                ans++;
                continue;
            }
            if (r1 != r2) {
                f[r1] = r2;
                dis[r1] = dis[y] - dis[x];
            }
        } else {
            if (r1 == r2 && ((dis[x] - dis[y]) % 3 + 3) % 3 != 1) {
                ans++;
                continue;
            }
            if (r1 != r2) {
                f[r1] = r2;
                dis[r1] = dis[y] - dis[x] + 1;
            }
        }
    }
    printf("%d\n", ans);
}

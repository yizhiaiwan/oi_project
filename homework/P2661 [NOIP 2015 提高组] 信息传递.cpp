//
// Created by yizhiaiwan on 2026/4/30.
// from:
// https://www.luogu.com.cn/problem/P2661
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,ans = 0x3fffffff;
int f[N],dis[N];
struct node {
    int x,y;
}a[N];
int find(int x) {
    if (f[x]!=x) {
        int root = find(f[x]);
        dis[x] += dis[f[x]];
        f[x] = root;
    }
    return f[x];
}

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i].y);
        a[i].x = i;
    }
    for (int i = 1; i <= n; i++) {
        int rx = find(a[i].x), ry = find(a[i].y);
        if (rx!=ry) {
            f[rx] = ry;
            dis[rx] = dis[a[i].y] - dis[a[i].x] + 1;
        }
        else {
            ans = min(ans,dis[a[i].y]+dis[a[i].x]+1);

        }
    }
    printf("%d",ans);
}
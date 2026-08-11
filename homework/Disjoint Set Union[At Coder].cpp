//
// Created by yizhiaiwan on 2026/8/3.
// from:
// https://atcoder.jp/contests/practice2/tasks/practice2_a
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int f[N];
int n,q;
int find(int x) {
    if (f[x] == x) return f[x];
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    int root_x = find(x), root_y = find(y); // 找两个集合的父节点
    if (root_x != root_y) {
        f[root_x] = root_y; // 合并两个集合
    }
}


int main() {
    scanf("%d%d",&n,&q);
    for (int i = 1;i<=n;i++) f[i] = i;
    for (int i = 1;i<=q;i++) {
        int opt,u,v;
        scanf("%d%d%d",&opt,&u,&v);
        if (opt==1) {
            if (find(u)==find(v)) {
                printf("1\n");
            }else {
                printf("0\n");
            }
        }else {
            merge(u,v);
        }
    }
}
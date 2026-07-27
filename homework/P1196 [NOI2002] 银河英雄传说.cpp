//
// Created by yizhiaiwan on 2026/5/5.
// from:
// https://www.luogu.com.cn/problem/P1196
//
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int f[N],dis[N],siz[N];
int t;
int find(int x) {
    if (f[x]==x) return x;
    int root = find(f[x]);
    dis[x] += dis[f[x]];
    f[x] = root;
    return root;
}

int main() {
    scanf("%d",&t);
    for (int i = 1;i<=N-1;i++) {
        f[i] = i;
        siz[i] = 1;
    }
    for (int i = 1;i<=t;i++) {
        int x,y;
        char opt;
        scanf("\n%c %d %d",&opt,&x,&y);
        int rx = find(x),ry = find(y);
        if (opt=='M') {
            if (rx!=ry) {
                f[rx] = ry;
                dis[rx] = siz[ry];
                siz[ry]+=siz[rx];
            }
        }
        else {
            if (rx==ry) {
                printf("%d\n",abs(dis[x]-dis[y])-1);
            }
            else {
                printf("-1\n");
            }
        }
    }
}
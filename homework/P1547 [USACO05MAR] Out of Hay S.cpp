//
// Created by yizhiaiwan on 2026/5/27.
// from:
// https://www.luogu.com.cn/problem/P1547
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+10,M = 1e4+10;
int n,m,ans;
struct edge{int x,y,w;}e[M];
int f[N];
int find(int x) {
    if (f[x]!=x) {
        return f[x] = find(f[x]);
    }
    return f[x];
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=m;i++) {
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    }
    for (int i = 1;i<=n;i++) {
        f[i] = i;
    }
    sort(e+1,e+m+1,[](edge a,edge b){return a.w<b.w;});

    for (int i = 1;i<=m;i++) {
        int x = e[i].x,y = e[i].y,w = e[i].w;
        int rx = find(x),ry = find(y);
        if (rx!=ry) {
            f[rx] = ry;
            ans = max(ans,w);
        }
    }
    printf("%d",ans);
}

//
// Created by yizhiaiwan on 2026/5/31.
// from:
// https://www.luogu.com.cn/problem/P1550
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int f[N];
struct edge{int x,y,w;}e[N];
int n,cnt;
int find(int x) {
    if (f[x]!=x) {
        return f[x] = find(f[x]);
    }
    return f[x];
}

int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        e[++cnt] = {i,n+1,x};
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            int x;
            scanf("%d",&x);
            if (x!=0) e[++cnt] = {i,j,x};
        }
    }
    sort(e+1,e+cnt+1,[](edge a,edge b){return a.w<b.w;});
    for (int i = 1;i<=n;i++) f[i] = i;
    int tot = 0,mst = 0;
    for (int i = 1;i<=cnt;i++) {
        int x = e[i].x,y = e[i].y,w = e[i].w;
        int rx = find(x),ry = find(y);
        if (rx!=ry) {
            f[rx] = ry;
            tot++;
            mst += w;
            if (tot == n) {
                break;
            }
        }
    }
    printf("%d",mst);
}
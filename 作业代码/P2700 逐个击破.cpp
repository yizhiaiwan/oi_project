//
// Created by yizhiaiwan on 2026/6/20.
// from:
// https://www.luogu.com.cn/problem/P2700
//
/*
 * 用kruskal算法跑最小生成树，在只剩k个连通块是停下
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,k;
long long ans,tot;
int f[N],vis[N];
struct edge {
    int u,v,w;
}e[N];
int find(int x) {
    if (f[x]!=x) {
        f[x] = find(f[x]);
    }
    return f[x];
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i = 1;i<=n;i++) {
        f[i] = i;
    }
    for (int i = 1;i<=k;i++) {
        int a;
        scanf("%d",&a);
        vis[a] = 1;
    }
    for (int i = 1;i<n;i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        tot+=e[i].w;
    }
    sort(e+1,e+n,[](edge a, edge b){return a.w>b.w;});
    for (int i = 1;i<n;i++) {
        int u = e[i].u,v = e[i].v,w = e[i].w;
        int ru = find(u),rv = find(v);
        if (ru!=rv) {
            if (vis[ru]==1 && vis[rv]==1) {

            }else {
                f[ru] = rv;
                vis[rv] = vis[ru]||vis[rv];
                ans+=w;
            }
        }
    }
    printf("%lld",tot-ans);
}
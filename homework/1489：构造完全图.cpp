//
// Created by yizhiaiwan on 2026/5/31.
// from:
// https://ybt.ssoier.cn/problem_show.php?pid=1489
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int f[N],sz[N];
int n,cnt;
struct node{int u,v,w;}e[N];
int find(int x) {
    if (f[x]!=x) {
        f[x] = find(f[x]);
    }
    return f[x];
}
long long ans;


int main() {
    scanf("%d",&n);
    for (int i = 1;i<n;i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for (int i = 1;i<=n;i++) {
        f[i] = i;
        sz[i] = 1;
    }
    sort(e+1,e+n,[](node a,node b){return a.w<b.w;});
    for (int i = 1;i<n;i++) {
        int u = e[i].u,v = e[i].v,w = e[i].w;
        int rx = find(u),ry = find(v);
        if (rx!=ry) {
            f[rx] = ry;
            ans+=((long long)sz[rx]*sz[ry]-1)*(w+1)+w;
            sz[ry] += sz[rx];
        }
    }
    printf("%lld",ans);
    return 0;
}
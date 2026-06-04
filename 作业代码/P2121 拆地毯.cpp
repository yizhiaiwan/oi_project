//
// Created by yizhiaiwan on 2026/6/2.
// from:
// https://www.luogu.com.cn/problem/P2121
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int f[N];
int n,m,ans,cnt,k;
struct node{int u,v,w;}e[N];
int find(int x) {
    if (f[x]!=x) {
        f[x] = find(f[x]);
    }
    return f[x];
}


int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1;i<=m;i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for (int i = 1;i<=n;i++) f[i] = i;
    sort(e+1,e+m+1,[](node a,node b){return a.w>b.w;});
    for (int i = 1;i<=m;i++) {
        int u = e[i].u,v = e[i].v,w = e[i].w;
        int rx = find(u),ry = find(v);
        if (rx!=ry) {
            f[rx] = ry;
            ans+=w;
            cnt++;
            if (cnt==k) break;
        }
    }
    printf("%d",ans);
    return 0;
}
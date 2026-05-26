//
// Created by yizhiaiwan on 2026/5/24.
// from:
// https://www.luogu.com.cn/problem/P3366
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int f[N];
int n,m,ans,cnt;
struct node{int u,v,w;}e[N];
int find(int x) {
    if (f[x]!=x) {
        f[x] = find(f[x]);
    }
    return f[x];
}


int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=m;i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for (int i = 1;i<=n;i++) f[i] = i;
    sort(e+1,e+m+1,[](node a,node b){return a.w<b.w;});
    for (int i = 1;i<=m;i++) {
        int u = e[i].u,v = e[i].v,w = e[i].w;
        int rx = find(u),ry = find(v);
        if (rx!=ry) {
            f[rx] = ry;
            ans+=w;
            cnt++;
            if (cnt == n-1) break;
        }
    }
    if (cnt!=n-1) {
        printf("orz");
        return 0;
    }
    printf("%d",ans);
    return 0;
}
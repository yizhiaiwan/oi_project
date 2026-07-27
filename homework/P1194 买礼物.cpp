//
// Created by yizhiaiwan on 2026/5/31.
// from:
// https://www.luogu.com.cn/problem/P1194
//
#include <bits/stdc++.h>
using namespace std;
const int N = 510*510;
int f[N];
int n,m,ans,cnt,tot;
struct edge{int x,y,z;}e[N];
int find(int x) {
    if (f[x]!=x) {
        f[x] = find(f[x]);
    }
    return f[x];
}

int main() {
    scanf("%d%d",&m,&n);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            int t;
            scanf("%d",&t);
            if (t!=0) {
                e[++cnt] = {i,j,t};
            }
        }
    }
    for (int i = 1;i<=n;i++) f[i] = i;
    sort(e+1,e+cnt+1,[](edge a,edge b){return a.z<b.z;});
    for (int i = 1;i<=cnt;i++) {
        int x = e[i].x,y = e[i].y,w = e[i].z;
        int rx = find(x),ry = find(y);
        if (rx!=ry) {
            f[rx] = ry;
            if (w>m) {
                ans+=m;
            }else {
                ans+=w;
            }
        }
    }
    for (int i = 1;i<=n;i++) {
        if (f[i]==i) {
            tot++;
        }
    }
    printf("%d",ans+tot*m);
}
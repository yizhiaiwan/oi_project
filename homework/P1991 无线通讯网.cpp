//
// Created by yizhiaiwan on 2026/6/11.
// from:
// https://www.luogu.com.cn/problem/P1991
//
#include <bits/stdc++.h>
using namespace std;
const int N = 510*510;
int s,p,cnt;
double ans;
int f[N];
int find(int x) {
    if (f[x]==x) return x;
    return f[x] = find(f[x]);
}
struct edge {
    int u,v;
    double w;
}e[N];

struct node {
    int x,y;
}a[N];
double get(int xa,int ya,int xb,int yb) {
    return sqrt(pow(xa-xb,2)+pow(ya-yb,2));
}

signed main() {
    scanf("%d%d",&s,&p);
    for (int i = 1;i<=p;i++) {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    for (int i = 1;i<=p;i++) f[i] = i;
    for (int i = 1;i<=p;i++) {
        for (int j = i;j<=p;j++) {
            if (i!=j) {
                e[++cnt] = {i,j,get(a[i].x,a[i].y,a[j].x,a[j].y)};
            }
        }
    }
    sort(e+1,e+cnt+1,[](edge a,edge b){return a.w<b.w;});
    int tot = 0;
    for (int i = 1;i<=cnt;i++) {
        int u = e[i].u,v = e[i].v;
        int ru = find(u),rv = find(v);
        if (ru!=rv) {
            f[ru] = rv;
            ans=e[i].w;
            tot++;
            if (tot == p-s) {
                printf("%.2lf",ans);
                return 0;
            }
        }
    }
    printf("%.2lf",ans);
    return 0;
}
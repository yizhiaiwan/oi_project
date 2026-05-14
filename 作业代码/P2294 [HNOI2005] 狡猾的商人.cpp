//
// Created by yizhiaiwan on 2026/5/5.
// from:
// https://www.luogu.com.cn/problem/P2294
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int f[N],dis[N];
int w,n,m;
int find(int x) {
    if (f[x]==x) return x;
    int root = find(f[x]);
    dis[x]+=dis[f[x]];
    f[x] = root;
    return f[x];
}


int main() {
    scanf("%d",&w);
    while(w--) {
        bool flag = false;
        scanf("%d%d",&n,&m);
        for (int i = 0;i<=n;i++) {
            f[i] = i;
            dis[i] = 0;
        }
        for (int i=1;i<=m;i++) {
            int x,y,v;

            scanf("%d%d%d",&x,&y,&v);
            int rx = find(--x),ry = find(y);
            if (rx!=ry) {
                f[rx] = ry;
                dis[rx] = dis[y]-dis[x]-v;
            }
            else {
                if (dis[y]-dis[x]!=v) {
                    flag = true;
                }
            }
        }
        if (flag==false) {
            printf("true\n");
        }
        else {
            printf("false\n");
        }
    }
}
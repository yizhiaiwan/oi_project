//
// Created by yizhiaiwan on 2026/6/12.\
// from:
// https://www.luogu.com.cn/problem/P1340
//
#include <bits/stdc++.h>
using namespace std;
const int N = 200*200;
struct edge{int x,y,w;}e[N];
int f[N];
int n,week;
int find(int x) {
    if (f[x]!=x) {
        return f[x] = find(f[x]);
    }
    return f[x];
}



int main() {
    scanf("%d%d",&n,&week);


    for (int i = 1;i<=week;i++) { // i = 边数
        for (int j = 1;j<=n;j++) f[j] = j;
        int tot = n; // 连通块个数
        int ans = 0;
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
        sort(e+1,e+i+1,[](edge a,edge b){return a.w<b.w;});
        for (int j = 1;j<=i;j++) {
            int x = e[j].x,y = e[j].y,w = e[j].w;
            int rx = find(x),ry = find(y);
            if (rx!=ry) {
                f[rx] = ry;
                ans+=w;
                tot--;
                if (tot==1) {
                    printf("%d\n",ans);
                    break;
                }
            }
        }
        if (tot!=1) {
            printf("-1\n");
        }
    }
}
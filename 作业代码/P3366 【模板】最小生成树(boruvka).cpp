//
// Created by yizhiaiwan on 2026/5/24.
// from:
// https://www.luogu.com.cn/problem/P3366
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct edge { int u,v,w; } e[N];
int f[N],best[N],mst,n,m,cnt;

int find(int x) {
    if (f[x] != x) {
        return f[x] = find(f[x]);
    }
    return f[x];
}
int boruvka() {
    int updated = 1;
    for (int i = 1;i<=n;i++) f[i] = i;
    while (updated) {
        updated = 0;
        memset(best,-1,sizeof(best));
        //遍历所有边，找到每个连通块的最小出边
        for (int i = 1;i<=m;i++) {
            int u = e[i].u,v = e[i].v,w = e[i].w;
            int ru = find(u),rv = find(v);
            if (ru == rv) continue;
            if (best[ru] == -1 || e[best[ru]].w > w) best[ru] = i;
            if (best[rv] == -1 || e[best[rv]].w > w) best[rv] = i;
        }
        // 根据最小出边合并连通块
        for (int i = 1;i<=n;i++) {
            if (best[i] == -1) continue;
            int u = e[best[i]].u,v = e[best[i]].v, w = e[best[i]].w;
            int ru = find(u),rv = find(v);
            if (ru == rv) continue;
            f[ru] = rv;
            mst += w;
            cnt++;
            updated = 1;
        }
    }
    return cnt == n-1 ? mst : -1;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=m;i++) {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    if (boruvka()==-1) {
        printf("orz");
    }
    else printf("%d",mst);

}
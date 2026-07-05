//
// Created by yizhiaiwan on 2026/6/9.
// from:
// https://www.luogu.com.cn/problem/P10378
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int f[N],dis[N],siz[N][2];
int n,m,max_ans,min_ans;
int find(int x) {
    if (f[x]!=x) {
        int root = find(f[x]);
        dis[x] ^= dis[f[x]];
        f[x] = root;
    }
    return f[x];
}


int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++) {
        f[i] = i;
        siz[i][0] = 1;
        siz[i][1] = 0;
    }
    for (int i = 1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        int ru = find(u),rv = find(v);
        if (ru!=rv) {
            f[ru] = rv;
            dis[ru] = dis[u]^1^dis[v];
            if (dis[ru]==0) {
                siz[rv][0]+=siz[ru][0];
                siz[rv][1]+=siz[ru][1];
            }
            else {
                siz[rv][0]+=siz[ru][1];
                siz[rv][1]+=siz[ru][0];
            }
        }
    }

    for (int i = 1;i<=n;i++) {
        find(i);
        if (f[i]==i) {
            min_ans+=min(siz[i][0],siz[i][1]);
            max_ans+=max(siz[i][0],siz[i][1]);
        }
    }
    printf("%d %d\n",min_ans,max_ans);

}
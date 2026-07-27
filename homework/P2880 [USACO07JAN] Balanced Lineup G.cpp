//
// Created by yizhiaiwan on 2026/5/10.
// from:
// https://www.luogu.com.cn/problem/P2880
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4;
struct node {
    int mx,mi;
} st[N][16];
int lg[N];
int n,q;
void init() {
    for (int i = 2;i<=n;i++) {
        lg[i] = lg[i>>1]+1;
    }
}
int main() {
    scanf("%d%d",&n,&q);
    init();
    for (int i = 1;i<=n;i++) {
        int v;
        scanf("%d",&v);
        st[i][0].mx = v;
        st[i][0].mi = v;
    }
    for (int j = 1;j<=lg[n];j++) {
        for (int i = 1;i+(1<<j)-1<=n;i++) {
            st[i][j].mx = max(st[i][j-1].mx,st[i+(1<<(j-1))][j-1].mx);
            st[i][j].mi = min(st[i][j-1].mi,st[i+(1<<(j-1))][j-1].mi);
        }
    }
    for (int i = 1;i<=q;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        int j = lg[y-x+1];
        printf("%d\n",max(st[x][j].mx,st[y-(1<<j)+1][j].mx)-min(st[x][j].mi,st[y-(1<<j)+1][j].mi));
    }
}
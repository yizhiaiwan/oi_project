//
// Created by yizhiaiwan on 2026/5/10.
// from:
// https://www.luogu.com.cn/problem/P1890
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int f[N][10],lg[N];
int n,m;

void init() {
    for (int i = 2;i<=n;i++) {
        lg[i] = lg[i>>1]+1;
    }
}

int main() {
    scanf("%d%d",&n,&m);
    init();
    for (int i = 1;i<=n;i++) {
        scanf("%d",&f[i][0]);
    }
    for (int j = 1;j<=lg[n];j++) {
        for (int i = 1;i+(1<<j)-1<=n;i++) {
            f[i][j] = __gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for (int i = 1;i<=m;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        int k = lg[y-x+1];
        printf("%d\n",__gcd(f[x][k],f[y-(1<<k)+1][k]));
    }
}
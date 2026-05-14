//
// Created by yizhiaiwan on 2026/5/5.
// from:
// https://www.luogu.com.cn/problem/P2251
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int f[N][20],lg[N];
int n,m;
void init() {
    for(int i=2;i<=n;i++) {
        lg[i] = lg[i>>1]+1;
    }
}

int main() {
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;i++) {
        scanf("%d",&f[i][0]);
    }
    for(int j=1;j<=lg[n];j++) {
        for (int i=1;i+(1<<j)-1<=n;i++) {
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for (int x = 1;x+m-1<=n;x++) {
        int y = x+m-1;
        int j = lg[m];
        printf("%d\n",min(f[x][j],f[y-(1<<j)+1][j]));
    }
}
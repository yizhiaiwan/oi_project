//
// Created by yizhiaiwan on 2026/6/21.
// from;
// https://www.luogu.com.cn/problem/P10265
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int g[N][N];
int n,m;
int tot,ans;

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++) {
            scanf("%d",&g[i][j]);
            if (i==m) {
                tot+=(g[i][j]==1);
            }
            if (j==m) {
                ans+=g[i][j]==1;
            }
        }
    }
    printf("%d %d %d",tot,ans,ans+tot);
}
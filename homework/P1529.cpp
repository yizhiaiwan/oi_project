//
// Created by yizhiaiwan on 2026/7/30.
// from:
// https://www.luogu.com.cn/problem/P1529
//
#include <bits/stdc++.h>
using namespace std;
const int N = 61;
int f[N][N][N];
int m,n = 52;

void Floyd() {
    for (int i = 1;i<=n;i++) {
        f[0][i][i] = 0;
    }
    for (int k = 1;k<=n;k++) {
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=n;j++) {
                f[k][i][j] = min(f[k-1][i][j],f[k-1][i][k]+f[k-1][k][j]);
            }
        }
    }
}





int main() {
    memset(f,0x3f,sizeof f);
    scanf("%d",&m);
    for (int i = 1;i<=m;i++) {
        char a,b;
        int x,y,w;
        cin>>a>>b>>w;
        if ('A'<=a && a<='Z') x = a-'A'+1;
        else x = a-'a'+27;
        if ('A'<=b && b<='Z') y = b-'A'+1;
        else y = b-'a'+27;
        f[0][x][y] = min(f[0][x][y],w);
        f[0][y][x] = min(f[0][y][x],w);
    }
    Floyd();
    int  ans = 1e9;
    char tot = 'Z';
    for (int i = 1;i<=25;i++) {
        if (f[n][26][i] < ans) {
            ans = f[n][26][i];
            tot = char(i-1+'A');
        }
    }
    printf("%c %d",tot,ans);
}
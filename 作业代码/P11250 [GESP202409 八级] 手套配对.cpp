//
// Created by yizhiaiwan on 2026/6/9.
// from:
// https://www.luogu.com.cn/problem/P11250
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3,mod = 1e9+7;
int A[N+10],C[N+10][N+10];
int t,n,m,k;
void init() {
    A[1] = 1;
    for (int i = 2;i<=N;i++) {
        A[i] = A[i-1]*i;
    }
    for (int i = 1;i<=N;i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1;j<i;j++) {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }
}


int main() {
    init();
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d%d",&n,&m,&k);
        int ans = ((C[n][k]*C[m][1]*C[m-2][1])/2)%mod;
        printf("%d\n",&ans);
    }
}
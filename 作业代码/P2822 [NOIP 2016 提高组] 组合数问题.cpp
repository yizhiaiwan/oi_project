//
// Created by yizhiaiwan on 2026/6/14.
// from:
// https://www.luogu.com.cn/problem/P2822
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int c[N][N],st[N][N];
int t,k;

void init() {
    st[0][0] = (c[0][0] == 0) ? 1 : 0;
    for (int i = 1;i<=2000;i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1;j<i;j++) {
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%k;

        }
    }
    for (int i = 1;i<=2000;i++) {
        for (int j = 1;j<=2000;j++) {
            st[i][j] += st[i-1][j]+st[i][j-1]-st[i-1][j-1];
            if (c[i][j]==0) {
                st[i][j]++;
            }
        }
        st[i][i] = st[i-1][i] + st[i][i-1] - st[i-1][i-1] + (c[i][i] == 0);
    }

}


int main() {
    scanf("%d%d",&t,&k);
    init();
    for (int i = 1;i<=t;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a<b) {
            printf("%d\n",st[a][a]);
        }
        else {
            printf("%d\n",st[a][b]);
        }
    }
    return 0;
}
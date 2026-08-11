//
// Created by yizhiaiwan on 2026/7/28.
// from:
// https://www.luogu.com.cn/problem/P1169
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+10;
int n,m,ans1,ans2;
int a[N][N],h[N][N],l[N][N],r[N][N];

void init() {
    for (int i = 1;i<=m;i++) {
        l[0][i] = 1;
        r[0][i] = m;
    }
}
void maxR() {
    init();
    for (int i = 1;i<=n;i++) {
        for (int j = 1,last = 1;j<=m;j++) {
            if (a[i][j] == 0) {
                l[i][j] = 1;
                last = j + 1;
            }else {
                l[i][j] = last;
            }
        }
        for (int j = m,last = m;j>=1;j--) {
            if (a[i][j] == 0) {
                r[i][j] = m;
                last = j-1;
            }else {
                r[i][j] = last;
            }
        }
        for (int j = 1;j<=m;j++) {
            if (a[i][j] == 0) {
                h[i][j] = 0;
                l[i][j] = 1;
                r[i][j] = m;
            }else {
                h[i][j] = h[i-1][j]+1;
                l[i][j] = max(l[i][j],l[i-1][j]);
                r[i][j] = min(r[i][j],r[i-1][j]);
                int len = (r[i][j]-l[i][j]+1);
                int e_len = min(h[i][j],len);
                ans1 = max(ans1,h[i][j] * len );
                ans2 = max(ans2,e_len*e_len);
            }
        }
    }
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            cin>>a[i][j];
            if ((i+j)&1) a[i][j] = !a[i][j];
        }
    }
    maxR();
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            a[i][j] = !a[i][j];
        }
    }
    maxR();
    cout<<ans2<<"\n"<<ans1;
}
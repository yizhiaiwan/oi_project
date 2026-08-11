//
// Created by yizhiaiwan on 2026/7/28.
// from:
// https://www.luogu.com.cn/problem/P4147
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m;
int a[N][N],h[N][N],l[N][N],r[N][N];

void init() {
    for (int i = 1;i<=m;i++) {
        l[0][i] = 1;
        r[0][i] = m;
    }
}

int maxR() {
    init();
    int ans = 0;
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
                ans = max(ans,h[i][j] * (r[i][j]-l[i][j]+1) );
            }
        }
    }
    return ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            char t;
            cin>>t;
            a[i][j] = (t=='F') ? 1:0;
        }
    }
    printf("%d",3*maxR());
}
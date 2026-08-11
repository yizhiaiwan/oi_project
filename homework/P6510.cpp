//
// Created by yizhiaiwan on 2026/7/27.
// from:
// https://www.luogu.com.cn/problem/P6510
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int a[N];
int n,ans;
int st_up[N],st_down[N];

signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }

    int up_top = 0, down_top = 0;
    for (int i = 1;i<=n;i++) {
        while (up_top && a[st_up[up_top]] >= a[i]) { // 单调增
            up_top--;
        }
        while (down_top && a[st_down[down_top]] < a[i]) { // 单调减
            down_top--;
        }
        int d = lower_bound(st_up+1,st_up+up_top+1,st_down[down_top])-st_up;
        if (d!=up_top+1) {
            ans = max(ans,i-st_up[d]+1);
        }
        st_up[++up_top] = i;
        st_down[++down_top] = i;
    }
    printf("%lld",ans == 1 ? 0:ans);
}
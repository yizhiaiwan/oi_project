//
// Created by yizhiaiwan on 2026/7/28.
// from:
// https://www.luogu.com.cn/problem/P2659
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int n,ans = -1;
int a[N],r[N],l[N];





signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    a[0] = a[n+1] = INT_FAST32_MIN;
    stack<int> st_l,st_r;
    for (int i = 0;i<=n+1;i++) { // 右边第一个小的
        while (!st_r.empty() && a[st_r.top()] > a[i]) {
            r[st_r.top()] = i;
            st_r.pop();
        }
        st_r.push(i);
    }
    for (int i = n+1;i>=0;i--) { // 左边第一个小的
        while (!st_l.empty() && a[st_l.top()] > a[i]) {
            l[st_l.top()] = i;
            st_l.pop();
        }
        st_l.push(i);
    }
    for (int i = 1;i<=n;i++) {
        int L = l[i]+1,R = r[i]-1;
        ans = max(ans,(R-L+1)*a[i]);
    }
    printf("%lld",ans);
}
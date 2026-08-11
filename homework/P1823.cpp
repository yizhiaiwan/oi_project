//
// Created by yizhiaiwan on 2026/7/27.
// from:
// https://www.luogu.com.cn/problem/P1823
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int a[N],sum[N];
int n,ans;



signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    stack<int> st;
    for (int i = 1;i<=n;i++) {
        sum[i] = 1;
        while (!st.empty() && a[st.top()] < a[i]) {// 单调栈找第一个小于他的
            ans+=sum[st.top()];
            st.pop();
        }
        if (!st.empty() && a[st.top()] == a[i]) {
            ans+=sum[st.top()];
            sum[i]+=sum[st.top()];
            st.pop();
        }
        ans+=!st.empty()&1;
        st.push(i);
    }
    printf("%lld\n",ans);
}
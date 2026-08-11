//
// Created by yizhiaiwan on 2026/7/27.
// from:
// https://www.luogu.com.cn/problem/P2866
//
#include <bits/stdc++.h>
using namespace std;
const int N = 8e4+10;
int h[N],r[N],c[N];
int n;
long long ans;


int main() {
    scanf("%d",&n);
    h[n+1] = 1e9+1;
    for (int i = 1;i<=n;i++) {
        scanf("%d",&h[i]);
    }
    stack<int> st;
    for (int i = 1;i<=n+1;i++) {// 单调栈，求右边第一个比自己大的数
        while (!st.empty() && h[st.top()] <= h[i]) {
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1;i<=n;i++) {
        c[i] = r[i]-(i+1);
        ans+=c[i];
    }
    printf("%lld",ans);
}
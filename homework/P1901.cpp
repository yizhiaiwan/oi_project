//
// Created by yizhiaiwan on 2026/7/27.
// from:
// https://www.luogu.com.cn/problem/P1901
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int h[N],v[N],l[N],r[N],sum[N];
int n,ans;





int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%d%d",&h[i],&v[i]);
    }
    stack<int> l_st,r_st;
    for (int i = 1;i<=n;i++) {// 单调栈,求右边第一个大的
        while (!r_st.empty() && h[r_st.top()] <= h[i]) {
            r[r_st.top()] = i;
            r_st.pop();
        }
        r_st.push(i);
    }
    for (int i = n;i>=1;i--) {// 单调栈,求左边第一个大的
        while (!l_st.empty() && h[l_st.top()] <= h[i]) {
            l[l_st.top()] = i;
            l_st.pop();
        }
        l_st.push(i);
    }
    for (int i = 1;i<=n;i++) {
        sum[l[i]] += v[i];
        sum[r[i]] += v[i];
    }
    for (int i = 1;i<=n;i++) {
        ans = max(ans,sum[i]);
    }
    printf("%d",ans);
}
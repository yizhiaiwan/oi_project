//
// Created by yizhiaiwan on 2026/7/27.
// from:
// https://www.luogu.com.cn/problem/P5788
//
#include <bits/stdc++.h>
using namespace std;
const int N = 3e6+10;
int n;
int a[N],r[N];






int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    stack<int> st;
    for (int i = 1;i<=n;i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            r[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1;i<=n;i++) {
        printf("%d ",r[i]);
    }
}
//
// Created by yizhiaiwan on 2026/6/21.
// from:
// https://www.luogu.com.cn/problem/P4549
//
#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int a[N];
int n;
int ans;



int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    ans = a[1];
    for (int i = 2;i<=n;i++) {
        ans = __gcd(a[i],ans);
    }
    cout<<abs(ans);
}
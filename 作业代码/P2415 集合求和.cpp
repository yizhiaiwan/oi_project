//
// Created by yizhiaiwan on 2026/6/14.
// from:
// https://www.luogu.com.cn/problem/P2415
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
int a[N];
int ans;


signed main() {
    int cnt = 0;
    while (cin>>a[++cnt]);
    for (int i = 1;i<=cnt;i++) {
        ans+=a[i]*pow(2,cnt-2);
    }
    cout<<ans;
}
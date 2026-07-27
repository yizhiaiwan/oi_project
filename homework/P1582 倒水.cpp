//
// Created by yizhiaiwan on 2026/7/24.
// from:
// https://www.luogu.com.cn/problem/P1582
//
#include <bits/stdc++.h>
using namespace std;
int n,k;



int cal(int x) {
    int cnt = 0;
    while (x) {
        if (x&1) cnt++;
        x>>=1;
    }
    return cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    int cnt_b = 0,a = n;
    while (1) {
        int cnt = __builtin_popcount(a);
        if (cnt<=k) {
            cout<<cnt_b;
            break;
        }
        int t = n & -n;
        cnt_b+=t;
        a += t;
    }
    return 0;
}
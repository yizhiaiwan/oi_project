//
// Created by yizhiaiwan on 2026/7/24.
// from:
// https://www.luogu.com.cn/problem/P1031
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];
int n,av,sum,cnt;





int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i = 1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    av = sum/n;
    for (int i = 1;i<=n-1;i++) {
        if (a[i]==av) continue;
        int t = a[i]-av;
        cnt++;
        a[i]-=t;
        a[i+1]+=t;
    }
    cout<<cnt;
}
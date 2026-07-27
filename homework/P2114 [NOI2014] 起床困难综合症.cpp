//
// Created by yizhiaiwan on 2026/7/24.
// from:
// https://www.luogu.com.cn/problem/P2114
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef pair<int,int> PII; // 1. op 2. value
PII a[N];
int n,m,ans;

int cmp(string s) {
    if (s == "AND") return 1;
    if (s == "OR") return 2;
    if (s == "XOR") return 3;
}
int cal(int x) {
    for (int i = 1;i<=n;i++) {
        if (a[i].first==1) x = x&a[i].second;
        else if (a[i].first==2) x = x|a[i].second;
        else if (a[i].first==3) x = x^a[i].second;
    }
    return x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i = 1;i<=n;i++) {
        string s;
        int t;
        cin>>s>>t;
        a[i].first = cmp(s);
        a[i].second = t;
    }
    int res = 0,st = 0;
    for (int i = 30;i>=0;i--) {
        res = cal(st);
        ans = max(ans,res);
        int t = st+(1<<i);
        if (t>m) continue;
        res = cal(t);
        if (res>ans) {
            ans = res;
            st+=1<<i;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
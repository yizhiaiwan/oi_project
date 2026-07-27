//
// Created by yizhiaiwan on 2026/7/22.
// from:
// https://www.luogu.com.cn/problem/P2949
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
struct node {
    int d,p;
}a[N];
int n;
priority_queue<int,vector<int>,greater<int>> que;



signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%lld%lld",&a[i].d,&a[i].p);
    }
    sort(a+1,a+n+1,[](node a, node b){return a.d<b.d;});
    int tot = 0, ans = 0;
    for (int i = 1;i<=n;i++) {
        tot ++;
        ans += a[i].p;
        que.push(a[i].p);
        if (tot>a[i].d) {
            tot--;
            ans -= que.top();
            que.pop();
        }
    }
    printf("%lld",ans);
}
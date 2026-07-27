//
// Created by yizhiaiwan on 2026/7/22.
// from:
// https://www.luogu.com.cn/problem/P4053
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
struct node {
    int t1,t2;
}a[N];
int n;
priority_queue<int> que;
signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%lld%lld",&a[i].t1,&a[i].t2);
    }
    sort(a+1,a+n+1,[](node a, node b){return a.t2<b.t2;});
    int tot = 0;
    for (int i = 1;i<=n;i++) {
        tot += a[i].t1;
        que.push(a[i].t1);
        if (tot>a[i].t2) {
            tot-=que.top();
            que.pop();
        }
    }
    printf("%lld",que.size());
}
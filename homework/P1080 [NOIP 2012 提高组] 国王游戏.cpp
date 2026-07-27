//
// Created by yizhiaiwan on 2026/7/23.
// from:
// https://www.luogu.com.cn/problem/P1080
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int n;
struct node {
    int l,r;
}a[N];

bool cmp(node a,node b) {
    return a.l*a.r<b.l*b.r;
}


signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<=n+1;i++) {
        scanf("%lld%lld",&a[i].l,&a[i].r);
    }
    sort(a+2,a+n+2,cmp);
    int sum_fac = a[1].l,ans = a[1].l;
    for (int i = 2;i<=n+1;i++) {
        ans = max(ans,sum_fac/a[i].r);
        sum_fac*=a[i].l;
    }
    printf("%lld",ans);
}
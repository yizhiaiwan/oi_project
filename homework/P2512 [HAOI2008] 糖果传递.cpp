//
// Created by yizhiaiwan on 2026/7/24.
// from:
// https://www.luogu.com.cn/problem/P2512
//
/*
 * 1.求出平均值
 * 2.求出c数组
 * 3.求出k值
 * 4.求出p
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int a[N],s[N],c[N];
int n,sum,ans;



signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<=n;i++) {
        scanf("%lld",&a[i]);
        s[i] = s[i-1]+a[i];
    }
    int av = s[n]/n;
    for (int i = 1;i<=n;i++) {
        c[i] = s[i]-a[1]-(i-1)*av;
    }
    sort(c+1,c+n+1);
    int k = c[(n+1)/2];
    for (int i = 1;i<=n;i++) {
        ans += abs(c[i]-k);
    }
    printf("%lld\n",ans);
}
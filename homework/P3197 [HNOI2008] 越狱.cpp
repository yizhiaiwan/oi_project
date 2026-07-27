//
// Created by yizhiaiwan on 2026/7/21.
// from:
// https://www.luogu.com.cn/problem/P3197
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 100003;
int n,m;
int q_pow(int a,int b) {
    int res = 1;
    while (b) {
        if (b&1) {
            res = res*a%mod;
        }
        a = a*a%mod;
        b>>=1;
    }
    return res;
}




signed main() {
    scanf("%lld%lld",&m,&n);
    int sum = q_pow(m,n);
    int ans = (sum - (m*q_pow(m-1,n-1))%mod+mod)%mod; // 错误数可能比总数大，所以要+mod
    cout<<ans;
}
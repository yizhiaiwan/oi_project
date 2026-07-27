//
// Created by yizhiaiwan on 2026/6/22.
// from:
// https://www.luogu.com.cn/problem/P10724
//
/*
 * 做一个位异或前缀和
 * 然后查询这个异或的值之前有没有过，如果有，就可以把完全平方数的值+b[i]的值
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
vector<int> st = {2,3,5,7,11,13,17,19,23,29};
int a[N],b[N],s[N];
int n,ans;



signed main() {
    scanf("%lld",&n);
    b[0] = 1;
    for (int i = 1;i<=n;i++) {
        scanf("%lld",&a[i]);
        s[i] = s[i-1];
        int id = 0;
        for (int j:st) {
            int t = 0;
            while (a[i]%j==0){
                a[i]/=j;
                t^=1;
            }
            if (t) {
                s[i]^=(1<<id);
            }
            id++;
        }
        ans+=b[s[i]]++;
    }
    printf("%lld\n", ans);
}
//
// Created by yizhiaiwan on 2026/7/22.
// from:
// https://www.luogu.com.cn/problem/P3545
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25e4+10;
int n;
struct node {
    int a,b;
}a[N];
set<int> st;
priority_queue<pair<int,int>> que;


signed main() {
    scanf("%lld",&n);
    for (int i = 1;i<=n;i++) scanf("%lld",&a[i].a);
    for (int i = 1;i<=n;i++) scanf("%lld",&a[i].b);
    //sort(a+1,a+1+n,[](node a, node b){return a.b<b.b;});
    int sum_goods = 0;
    for (int i = 1;i<=n;i++) {
        sum_goods+=a[i].a;
        que.push({a[i].b,i});
        sum_goods-=a[i].b;
        st.insert(i);
        if (sum_goods < 0) {
            sum_goods+=que.top().first;
            st.erase(que.top().second);
            que.pop();
        }
    }
    printf("%lld\n",st.size());
    for (auto i:st) {
        printf("%lld ",i);
    }
}
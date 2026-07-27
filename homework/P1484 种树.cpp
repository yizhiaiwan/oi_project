//
// Created by yizhiaiwan on 2026/7/22.
// from:
// https://www.luogu.com.cn/problem/P1484
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 450000+1000;
priority_queue<pair<int,int>> q;
int n,k;
struct node {
    int l,r,v;
}s[N];
bool vis[N];
void init() {
    for (int i = 1;i<=n;i++) {
        q.push({s[i].v,i});
        s[i].l = i-1;
        s[i].r = i+1;
        vis[i] = false;
    }
}



signed main() {
    scanf("%lld%lld",&n,&k);
    for (int i = 1;i<=n;i++) {
        scanf("%lld",&s[i].v);
    }
    init();
    int cnt = n;
    int ans = 0;
    for (int i = 1;i<=k;i++) {
        while (q.size() && vis[q.top().second]) q.pop();
        if (q.empty()) break;
        int part_t = q.top().second;
        q.pop();
        if (s[part_t].v<0) break;
        ans+=s[part_t].v;
        int l = s[part_t].l, r = s[part_t].r;
        vis[l] = vis[r] = true;
        s[++cnt] = {s[l].l,s[r].r,s[l].v+s[r].v-s[part_t].v};
        s[s[l].l].r = cnt;
        s[s[r].r].l = cnt;
        q.push({s[cnt].v,cnt});
    }
    printf("%lld",ans);
}
//
// Created by yizhiaiwan on 2026/8/4.
// from:
// https://www.luogu.com.cn/problem/P2392
//
#include <bits/stdc++.h>
using namespace std;
int s[10];
int a[1010];
int cnt,tot;
int ans = 1e9;
void dfs(int x,int l,int r) {
    if (x>cnt) {
        ans = min(ans,max(l,r));
        return;
    }
    dfs(x+1,l+a[x],r);
    dfs(x+1,l,r+a[x]);
}


int main() {
    for (int i = 1;i<=4;i++) {
        scanf("%d",&s[i]);
    }
    for (int i = 1;i<=4;i++) {
        for (int j = 1;j<=s[i];j++) {
            scanf("%d",&a[j]);
        }
        ans = 1e9;
        cnt=s[i];
        dfs(1,0,0);
        tot+=ans;
    }
    printf("%d",tot);
}
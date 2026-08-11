//
// Created by yizhiaiwan on 2026/8/4.
// from:
// https://ybt.ssoier.cn/problem_show.php?pid=1440
//
#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[10];
int ans;

void dfs(int x,int cnt) {
    if (x == k) {
        if (cnt >= a[x-1]) ans++;
        return;
    }
    for (int i = a[x-1];i <= cnt/(k-x+1);i++) {
        a[x] = i;
        dfs(x+1,cnt-i);
    }
}





int main() {
    scanf("%d%d",&n,&k);
    a[0] = 1;
    dfs(1,n);
    printf("%d\n",ans);
    return 0;
}
//
// Created by yizhiaiwan on 2026/8/6.
// from:
// https://www.luogu.com.cn/problem/P1120
//
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n,sum = 0,res,ans;
int cnt = 0;
int a[N],vis[N];

void read() {
    for (int i = 1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        if (x>50) continue;
        a[++cnt] = x,sum+=x;
    }
}

bool dfs(int len,int sta,int now) {
    if (now == res - 1) return 1;
    if (len == 0) return dfs(ans,1,now+1);
    for (int i = sta;i<=cnt;i++) {
        if (!vis[i] && a[i]<=len) {
            vis[i] = 1;
            if (dfs(len-a[i],i+1,now)) return 1;
            vis[i] = 0;
            if (len == ans || len-a[i] == 0) return 0;
            while (a[i] == a[i+1]) i++;
        }
    }
    return 0;
}


int main() {
    scanf("%d",&n);
    read();
    sort(a+1,a+n+1,greater<>());
    for (int i = a[1];i<=sum;i++) {
        if (sum % i!=0) continue;
        res = sum/i;
        ans = i;
        if (dfs(ans,1,0)) {
            printf("%d\n",ans);
            return 0;
        }
    }
    return 0;
}
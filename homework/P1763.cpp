//
// Created by yizhiaiwan on 2026/8/6.
// from:
// https://www.luogu.com.cn/problem/P1763
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int n,m,g,deep;
int ans[N],last[N];
bool flag = false;
void dfs(int a,int b,int d) {
    if (b>1e6 && deep!=d) return;
    if (d == deep) {
        if (b%a != 0) return;
        if (b / a <= last[d-1]) return ;
        flag = true;
        last[d] = b/a;
        if (last[d] < ans[d]) memcpy(ans,last,sizeof ans);
        return;
    }
    for (int i = max(b/a+1,last[d-1]+1);i<=ans[deep];i++) {
        if (b*(deep-d+1) < a*i) break;
        last[d] = i;
        int nb = b*i;
        int na = a*i-b;
        g = __gcd(na,nb);
        nb/=g;
        na/=g;
        dfs(na,nb,d+1);
    }
}


signed main() {
    scanf("%lld%lld",&n,&m);
    if (n%m == 0) {
        printf("%lld\n",n/m);
        return 0;
    }
    g = __gcd(m,n);
    n /= g;
    m /= g;
    for (deep = 2;;deep++) {
        ans[1] = 0;
        ans[deep] = INT32_MAX;
        dfs(n,m,1);
        if (flag) break;
    }
    for (int i = 1;i<=deep;i++) printf("%lld ",ans[i]);
}
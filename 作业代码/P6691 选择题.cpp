//
// Created by yizhiaiwan on 2026/4/26.
// from:
// https://www.luogu.com.cn/problem/P6691
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10,mod = 998244353;
int n,ans = 1,cnt;
int f[N],dis[N],siz[N],num[N];
int find(int x) {
    if (f[x]!=x) {
        const int root = find(f[x]);
        dis[x]+=dis[f[x]];
        f[x] = root;
    }
    return f[x];
}

signed main() {
    scanf("%lld",&n);
    for (int i = 1;i <= n;i++) {
        f[i] = i;
        siz[i] = 1;
    }
    for (int i = 1;i <= n;i++) {
        int a,opt;
        scanf("%lld%lld",&a,&opt);
        int r1 = find(i),r2 = find(a);
        if (r1==r2 && opt==(dis[i]-dis[a]&1)){
            printf("No answer\n");
            return 0;
        }
        if (r1!=r2) {
            f[r2] = r1;
            siz[r1]+=siz[r2];
            if (opt==1) dis[r2] = dis[i]-dis[a];
            else dis[r2] = dis[i]-dis[a]+1;
        }
    }
    for (int i = 1;i <= n;i++) {
        int root = find(i);
        if (abs(dis[i]%2)==1) num[root]++;
    }
    for (int i = 1;i <= n;i++) {
        if (f[i]==i) {
            ans = ans*2%mod;
            cnt+=max(num[i],siz[i]-num[i]);
        }
    }
    printf("%lld\n%lld\n%lld\n",ans,cnt,n-cnt);
}
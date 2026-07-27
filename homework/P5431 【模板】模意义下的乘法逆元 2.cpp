//
// Created by yizhiaiwan on 2026/7/20.
// from:
// https://www.luogu.com.cn/problem/P5431
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e6+10;
int n,p,k,ans;
int a[N];
int s[N],e[N];

int read() {
    int f = 1,res = 0;
    char c = getchar();
    while (c<'0'||c>'9') {
        if (c=='-') f=-1;
        c=getchar();
    }
    while ('0'<=c&&c<='9') {
        res = res*10+c-'0';
        c = getchar();
    }
    return res*f;
}
int q_pow(int a,int b) {
    int res = 1;
    while (b) {
        if (b&1) {
            res *= a;
            res %= p;
        }
        a*=a;
        a%=p;
        b>>=1;
    }
    return res;
}

signed main() {

    n = read(),p = read(),k = read();
    s[0] = e[n+1] = 1;
    for (int i = 1;i<=n;i++) {
        a[i] = read();
        s[i] = s[i-1]*a[i]%p;
    }
    for (int i = n;i>=1;i--) e[i] = e[i+1]*a[i]%p;
    int k1 = 1;
    for (int i = 1;i<=n;i++) {
        k1 = k1*k%p;
        ans = (ans+s[i-1]*e[i+1]%p*k1)%p;
    }
    printf("%lld",(ans*q_pow(s[n],p-2)%p+p)%p);
}
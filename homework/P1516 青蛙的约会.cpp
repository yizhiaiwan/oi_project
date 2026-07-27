//
// Created by yizhiaiwan on 2026/7/5.
// from;
// https://www.luogu.com.cn/problem/P1516
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,y,m,n,L;


int exgcd(int a,int b,int &x,int &y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y = y-(a/b)*x;
    return d;
}

signed main() {
    scanf("%d%d%d%d%d",&x,&y,&m,&n,&L);
    int a = n-m,b = L,c=x-y;
    int d = exgcd(a,b,x,y);
    if (c%d!=0) {
        printf("Impossible");
        return 0;
    }
    x*=c/d;
    int t = abs(b/d);
    printf("%lld",(x%t+t)%t);
    return 0;
}
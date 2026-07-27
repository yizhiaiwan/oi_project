//
// Created by yizhiaiwan on 2026/7/5.
// from:
// https://www.luogu.com.cn/problem/P1082
//
#include <bits/stdc++.h>
using namespace std;
int a,b,x,y;


int exgcd(int a,int b,int &x,int &y) {
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y = y - (a/b) * x;
    return d;
}

int main() {
    scanf("%d%d",&a,&b);
    int d = exgcd(a,b,x,y);
    int t = b/d;
    cout<<(x%t+t)%t;
}
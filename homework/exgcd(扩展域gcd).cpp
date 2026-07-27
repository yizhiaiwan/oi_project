//
// Created by yizhiaiwan on 2026/7/5.
//
#include <bits/stdc++.h>
using namespace std;


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
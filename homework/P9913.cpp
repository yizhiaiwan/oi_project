//
// Created by yizhiaiwan on 2026/8/8.
// from:
// https://www.luogu.com.cn/problem/P9913?contestId=347124
//
#include <bits/stdc++.h>
using namespace std;
int t,n;



int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        if (n!=2 && n!=3 && n!=5) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
}
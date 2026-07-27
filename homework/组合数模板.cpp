//
// Created by yizhiaiwan on 2026/6/7.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
// I will sleeping now
// Q(m,n) = C(m,n)*Q(m,m)
// A(m,n) = n!/(n-m)!
// n==m A(m,n) = n!
// C(m,n) = n!/m!(n-m)!
void init(int n) {
    vector<int> A(N);
    vector<vector<int>> C(N);
    for (int i = 1;i<=n;i++) {
        A[i] = A[i-1]*i;
    }

    for (int i = 1;i<=n;i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1;j<i;j++) {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }
}
//
// Created by yizhiaiwan on 2026/8/7.
// from:
// https://www.luogu.com.cn/problem/B3644
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n;
int d[N];
vector<vector<int>> g(N);
vector<int> ans;
void Topological_sort() {
    queue<int> que;
    for (int i = 1;i<=n;i++) {
        if (d[i]==0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int top = que.front();
        que.pop();
        ans.push_back(top);
        for (int i:g[top]) {
            if (--d[i]==0) {
                que.push(i);
            }
        }
    }
}


int main() {
    scanf("%d",&n);
    for (int i = 1;i<=n;i++) {
        int x = -1;
        while (x!=0) {
            scanf("%d",&x);
            g[i].push_back(x);
            if (x!=0) {
                d[x]++;
            }
        }
    }
    Topological_sort();
    for (int i:ans) {
        printf("%d ",i);
    }
}
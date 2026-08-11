//
// Created by yizhiaiwan on 2026/7/28.
// from:
// https://www.luogu.com.cn/problem/P1168
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
priority_queue<int> l;
priority_queue<int,vector<int>,greater<int>> r;
int n;

void insert(int x) {
    if (l.empty()||x<l.top()) l.push(x);
    else r.push(x);
    if (l.size()>r.size()+1) {
        r.push(l.top());
        l.pop();
    }
    if (l.size()<r.size()){
        l.push(r.top());
        r.pop();
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for (int i = 1;i<=n;i++) {
        int a;
        cin>>a;
        insert(a);
        if (i&1)cout<<l.top()<<"\n";
    }
}
//
// Created by yizhiaiwan on 2026/7/24.
// from:
// https://www.luogu.com.cn/problem/P1106
//
#include <bits/stdc++.h>
using namespace std;
stack<int> st;
string s;
int k;

void print() {
    vector<int> v;
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    int j = v.size() - 1;
    while (v[j] == 0 && j >= 0) j--;
    if (j < 0) {
        cout << 0;
        return;
    }
    for (int i = j; i >= 0; i--) {
        cout << v[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++) {
        int t = s[i] - '0';
        while (!st.empty() && st.top() > t && k > 0) {
            st.pop();
            k--;
        }
        st.push(t);
    }
    while (k > 0 && !st.empty()) {
        k--;
        st.pop();
    }
    print();
    return 0;
}

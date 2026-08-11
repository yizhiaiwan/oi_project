//
// Created by yizhiaiwan on 2026/7/28.
// from:
// https://www.luogu.com.cn/problem/P1950
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m;
long long ans;
int a[N][N],h[N][N];
typedef pair<int,int> PII;


void maxR() {
    for (int i = 1;i<=n;i++) {
        stack<PII> st;
        long long s = 0;
        for (int j = 1;j<=m;j++) {
            if (a[i][j]==0) {
                while (!st.empty())
                    st.pop();
                s = 0;
                h[i][j] = 0;
            }else {
                int w = 1;
                h[i][j] = h[i-1][j]+1;
                while (!st.empty() && st.top().first >= h[i][j]) {
                    w+=st.top().second;
                    s-=st.top().first*st.top().second;
                    st.pop();
                }
                st.push({h[i][j],w});
                s+=h[i][j]*w;
                ans+=s;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            char t;
            cin>>t;
            a[i][j] = t=='.' ? 1:0;
        }
    }
    maxR();
    cout<<ans;
}
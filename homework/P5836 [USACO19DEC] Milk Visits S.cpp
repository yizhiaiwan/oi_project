//
// Created by yizhiaiwan on 2026/5/10.
// from:
// https://www.luogu.com.cn/problem/P5836
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int f[N];
vector<int> g[N];
string s;
int n,m;
vector<int> ans;
void dfs(int x,int pre) {
    for (auto& i:g[x]) {
        if (i!=pre) { //注意要分开判断
            if (s[i]==s[x])
                f[i] = f[x];

            dfs(i,x);
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    cin>>s;
    s = " "+s;
    for (int i = 1;i<=n;i++)
        f[i] = i;

    for (int i = 1;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for (int i = 1;i<=m;i++) {
        int x,y;
        char opt;
        cin>>x>>y>>opt;
        if (f[x]==f[y]) {
            if (s[x]==opt) {
                ans.push_back(1);
            }
            else {
                ans.push_back(0);
            }
        }
        else {
            ans.push_back(1);
        }
    }
    for (auto& i:ans) {
        printf("%d",i);
    }
}
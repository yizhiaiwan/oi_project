//
// Created by yizhiaiwan on 2026/5/10.
// from:
// https://www.luogu.com.cn/problem/P5836
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int f[N][21],dep[N];
vector<int> g[N];
int n,m;
char st[N];
string ans;
void dfs(int x,int pre) {
    dep[x] = dep[pre]+1;
    for (int i = 1;i<=20;i++) {
        f[x][i] = f[f[x][i-1]][i-1];
    }
    for (int& i:g[x]) {
        if (i!=pre) dfs(i,x);
    }
}
int LCA(int a,int b) {
    if (dep[a]<dep[b]) swap(a,b);
    for (int i = 20;i>=0;i--) {
        if (dep[f[a][i]]>=dep[b]&&st[a]==st[b]) {
            a = f[a][i];
        }
    }
    if (a==b) return 1;

    for (int i = 20;i>=0;i--) {
        if (f[a][i]!=f[b][i]&&st[a]==st[b]) {
            a = f[a][i],b = f[b][i];
        }
    }
    if (a!=b) return 2;
    return 1;
}
int main() {
    scanf("%d%d",&n,&m);
    scanf("%s",st+1);

    for (int i = 1;i<n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for (int i = 1;i<=m;i++) {
        int x,y;
        char z;
        scanf("%d %d %c",&x,&y,&z);
        if (LCA(x,y)==1 && st[x]==z) {
            ans+="1";
        }
        else if (LCA(x,y)==1 && st[x]!=z) {
            ans+="0";
        }
        else {
            ans+="1";
        }
    }
    cout<<ans;
}
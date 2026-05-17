//
// Created by yizhiaiwan on 2026/5/17.
// from:
// https://www.luogu.com.cn/problem/P4281
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int f[N][21],deps[N];
int n,m;
vector<int> g[N];
void dfs(int x,int pre) {
    deps[x] = deps[pre]+1;
    f[x][0] = pre;
    for (int i = 1;i<=20;i++) {
        f[x][i] = f[f[x][i-1]][i-1];
    }
    for (auto& i:g[x]) {
        if (i!=pre) {
            dfs(i,x);
        }
    }
}
int LCA(int x,int y) {
    if (deps[x]<deps[y]) {
        swap(x,y);
    }
    for (int i = 20;i>=0;i--) {
        if (deps[f[x][i]]>=deps[y]) {
            x = f[x][i];
        }
    }
    if (x==y) return y;
    for (int i = 20;i>=0;i--) {
        if (f[x][i]!=f[y][i]) {
            x = f[x][i],y = f[y][i];
        }
    }
    return f[x][0];
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<n;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for (int i = 1;i<=m;i++) {
        int x,y,z,ans,pot;
        scanf("%d%d%d",&x,&y,&z);
        int a = LCA(x,y),b = LCA(y,z),c = LCA(x,z);
        if (a==b) {
            pot = c;
        }
        else if(b==c) {
            pot = a;
        }
        else if (a==c) {
            pot = b;
        }
        ans = deps[x]+deps[y]+deps[z]-deps[a]-deps[b]-deps[c];
        printf("%d %d\n",pot,ans);
    }
}
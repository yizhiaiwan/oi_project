//
// Created by yizhiaiwan on 2026/6/26.
// from:
// https://www.luogu.com.cn/problem/P10379
//
/*
 * 使用dfs算法遍历，使用string记录每一次遍历的顺序，最后判断顺序有没有相同的
 * ps:直接把这一坨string扔进set最后求set的size就行了
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n,m;
int g[N][N];
bool vis[N][N];
set<string> st;
vector<pair<int,int>> que = {{1,0},{0,1},{-1,0},{0,-1}};

void dfs(int x,int y,int color,string &order) {
    int j = 0;
    for (pair i:que) {
        j++;
        int xt = x+i.first;
        int yt = y+i.second;
        if ( xt <= 0 || yt <= 0 || xt > n || yt > m ) continue;
        if (!vis[xt][yt] && g[xt][yt]==color) {
            vis[xt][yt] = true;
            if (j==1) {
                order+="d";
            }else if (j==2) {
                order+="r";
            }else if (j==3) {
                order+="u";
            }else {
                order+="l";
            }
            dfs(xt,yt,color,order);
            order+=" ";
        }
    }
}



int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            scanf("%d",&g[i][j]);
        }
    }
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            if (vis[i][j]==false) {
                vis[i][j] = true;
                string past_string;
                dfs(i,j,g[i][j],past_string);
                st.insert(past_string);
            }
        }
    }
    cout<<st.size();
}
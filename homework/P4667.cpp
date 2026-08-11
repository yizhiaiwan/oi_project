//
// Created by yizhiaiwan on 2026/8/3.
// from:
// https://www.luogu.com.cn/problem/P4667
//
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
char g[N][N],vis[N][N];
int n,m,ans = 1e9;
struct dirct {
    int x,y;
}dir[4] = {{-1,-1},{1,1},{-1,1},{1,-1}},
 e[4]   = {{0,0},{1,1},{0,1},{1,0}};
char r[5] = "\\\\//";  // {'\\', '\\', '/', '/'}
struct node {
    int x,y,dis;
};
void bfs(int x,int y) { // 01bfs
    memset(vis,0,sizeof vis);
    deque<node> que;
    que.push_back({x,y,0});
    while (!que.empty()) {
        node top = que.front();
        que.pop_front();
        int t_x = top.x,t_y = top.y;
        if (vis[t_x][t_y]) continue;
        vis[t_x][t_y] = 1;
        if (t_x == n && t_y == m) {
            ans = min(ans,top.dis);
        }
        for (int i = 0;i < 4;i++) {
            int new_x = t_x+dir[i].x;
            int new_y = t_y+dir[i].y;
            if (new_x > n || new_x < 0 || new_y > m || new_y < 0 || vis[new_x][new_y]) continue;
            int dir_x = t_x+e[i].x;
            int dir_y = t_y+e[i].y;
            if (g[dir_x][dir_y] == r[i]) {
                que.push_front({new_x,new_y,top.dis});
            }else {
                que.push_back({new_x,new_y,top.dis+1});
            }
        }
    }
}


int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=m;j++) {
            scanf(" %c",&g[i][j]);
        }
    }
    bfs(0,0);
    if (ans == 1e9) {
        printf("NO SOLUTION");
        return 0;
    }
    printf("%d\n",ans);
}
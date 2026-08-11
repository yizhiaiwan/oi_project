//
// Created by yizhiaiwan on 2026/8/5.
// from:
// https://www.luogu.com.cn/problem/P5195
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m;
int g[N][N];
bool vis1[N][N],vis2[N][N];
int sx,sy,ex,ey;
int ans = 1e9;
int nt[4][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
};
struct node {
    int x,y,d;
    bool opt = false;
};
int bfs(int x,int y,int xx,int yy) {
    memset(vis1,0,sizeof vis1);
    memset(vis2,0,sizeof vis2);
    queue<node> que;
    vis1[x][y] = true;
    que.push({x,y,0,false});
    while (!que.empty()) {
        node top = que.front();
        que.pop();
        if (top.x==xx && top.y == yy && top.opt) {
            return top.d;
        }
        for (int i = 0;i<4;i++) {
            int xt = top.x+nt[i][0];
            int yt = top.y+nt[i][1];
            if (xt < 0 || xt >= n || yt < 0 || yt >= m) continue;
            if (g[xt][yt] == 1) continue;
            if (!top.opt && g[xt][yt] == 3) continue;
            bool nopt = top.opt || (g[xt][yt] == 4);
            if (nopt == false) {
                if (vis1[xt][yt]) continue;
                vis1[xt][yt] = true;
            }else {
                if (vis2[xt][yt]) continue;
                vis2[xt][yt] = true;
            }
            que.push({xt,yt,top.d+1,nopt});
        }
    }
    return -1;
}


int main() {
    scanf("%d%d",&m,&n);
    for (int i = 0;i<n;i++) {
        int cnt = 0;
        for (int j = 0;j<m;j++) {
            scanf("%d",&g[i][cnt]);
            if (g[i][cnt]==2) {
                sx = i;
                sy = cnt;
            }
            if (g[i][cnt]==3) {
                ex = i;
                ey = cnt;
            }
            cnt++;
        }
    }
    ans = min(ans,bfs(sx,sy,ex,ey));
    printf("%d",ans);
}